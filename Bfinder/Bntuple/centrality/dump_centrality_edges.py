#!/usr/bin/env python3
"""Dump the 200 HFtowers bin edges of a CentralityTable payload to a text file.

The edges are what CentralityBinProducer uses: hiBin = first i with hiHF >= edge[i]
(edges are descending, i = 0 is the most central bin); 199 otherwise.
Use with hiBinFromHF() in CentralityFromHF.h to re-bin hiHF offline with any table
(nominal / SysUp / SysDown) without re-running the forest.

Needs cmsenv (uses `conddb`).

  # from a local sqlite file (tag name is read from the file if omitted)
  python3 dump_centrality_edges.py --db CentralityTable_..._Nominal.db -o edges/PbPb2024_data_Nominal.txt
  # from the conditions DB (e.g. a tag that is already inside a GlobalTag)
  python3 dump_centrality_edges.py --tag CentralityTable_HFtowers200_DataPbPb_periHYDJETshape_Run3v1302x04_Nominal_Offline -o edges/PbPb2023_data_Nominal.txt
"""
import argparse
import re
import sqlite3
import subprocess


def conddb(args, db=None):
    cmd = ["conddb"] + (["--db", db] if db else []) + args
    return subprocess.run(cmd, check=True, capture_output=True, text=True).stdout


def latest_payload_hash(tag, db=None):
    # `conddb list TAG` prints one IOV per line; the payload hash is a 40-char hex string
    hashes = re.findall(r"\b[0-9a-f]{40}\b", conddb(["list", tag], db))
    if not hashes:
        raise RuntimeError("no payload found for tag %s" % tag)
    return hashes[-1]


def tag_from_sqlite(db, wanted=None):
    tags = [r[0] for r in sqlite3.connect(db).execute("select NAME from TAG")]
    if wanted:
        if wanted not in tags:
            raise RuntimeError("tag %s not in %s (has: %s)" % (wanted, db, tags))
        return wanted
    # SysUp/SysDown files also contain the Nominal tag: pick the one matching the file name
    for t in tags:
        for var in ("SysUp", "SysDown"):
            if var in db and t.endswith(var):
                return t
    if len(tags) != 1:
        raise RuntimeError("several tags in %s, pass --tag: %s" % (db, tags))
    return tags[0]


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--db", help="sqlite file; omit to read --tag from the conditions DB")
    p.add_argument("--tag", help="tag name (required without --db)")
    p.add_argument("-o", "--output", required=True)
    a = p.parse_args()

    tag = tag_from_sqlite(a.db, a.tag) if a.db else a.tag
    if not tag:
        p.error("--tag is required without --db")
    payload = conddb(["dump", latest_payload_hash(tag, a.db)], a.db)
    edges = [float(x) for x in re.findall(r"<bin-edge>([^<]+)</bin-edge>", payload)]
    if len(edges) != 200 or edges != sorted(edges, reverse=True):
        raise RuntimeError("unexpected table: %d edges" % len(edges))

    with open(a.output, "w") as f:
        f.write("# %s\n# source: %s\n" % (tag, a.db or "conditions DB"))
        f.write("\n".join("%.6f" % e for e in edges) + "\n")
    print("%s: %d edges, hiBin0 >= %.1f GeV, hiBin199 >= %.3f GeV" % (a.output, len(edges), edges[0], edges[-1]))


if __name__ == "__main__":
    main()
