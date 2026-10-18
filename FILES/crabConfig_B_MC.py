"""Forest + Bfinder over B-meson MC (B+ -> J/psi K+, B0 -> J/psi K*0, Bs -> J/psi phi), official or private.

Set the mode of each sample in MODES below ("official", "private" or "no_run"), cmsenv in the CMSSW area of
the campaign (PbPb 2025: CMSSW_15_1_X, all others: CMSSW_14_1_X), source crab-setup.sh, then
    python3 Bfinder/FILES/crabConfig_B_MC.py               # list what would be submitted (inputs checked in DAS)
    python3 Bfinder/FILES/crabConfig_B_MC.py --submit      # submit
"""
from mc_crab_common import PTHAT_BINS, check_modes, main, make_task, private_inputs

ANALYSIS = {"work_area": "crab_projects_B", "out_label": "Bmesons"}

BFINDER_CHANNEL_SWITCHES = {
    "bplus": (1, 0, 0, 0, 0, 0, 0),
    "bzero": (0, 0, 0, 1, 0, 0, 0),
    "bs": (0, 0, 0, 0, 0, 1, 0),
}

DECAY_NAMES = {
    "bplus": "Bplus_to_JPsiK",
    "bzero": "B0_to_JPsiKStar",
    "bs": "Bs_to_JPsiPhi",
}

# Official global-DBS samples: primary dataset ({pthat} filled in); processing = campaign default.
OFFICIAL_SAMPLES = {
    ("pbpb23", "bplus"): {"primary": "BplusToJPsiKplus_pThat-{pthat}_TuneCP5_5p36TeV_pythia8-evtgen"},
    ("pbpb23", "bs"): {"primary": "B0sToJPsiPhi_pThat-{pthat}_TuneCP5_5p36TeV_pythia8-evtgen"},
    ("pbpb23", "bzero"): {"primary": "B0ToJPsiKStar_pThat-{pthat}_TuneCP5_5p36TeV_pythia8-evtgen"},
    ("ppref24", "bplus"): {"primary": "BplusToJPsiKplus_pThat-{pthat}_TuneCP5_5p36TeV_pythia8-evtgen"},
    # PbPb 2024: defined in McM (CMSSW_14_1_9_patch3), not produced yet
    ("pbpb24", "bplus"): {"primary": "BplusToJPsiKplus_pThat-{pthat}_TuneCP5_5p36TeV_pythia8-evtgen"},
    ("pbpb24", "bs"): {"primary": "B0sToJPsiPhi_pThat-{pthat}_TuneCP5_5p36TeV_pythia8-evtgen"},
    ("pbpb24", "bzero"): {"primary": "B0ToJPsiKStar_pThat-{pthat}_TuneCP5_5p36TeV_pythia8-evtgen"},
}

# Private MiniAOD in phys03: a pattern with {pthat} (a '*' is resolved in DAS) or an explicit {pthat: dataset} dict.
PRIVATE_SAMPLES = {
}


######################################################################################################################################################
###################################          MODES: "official" | "private" | "no_run"          ###################################
######################################################################################################################################################

MODES = {
    # ppRef 2024 (official: B+)
    ("ppref24", "bplus"): "no_run",
    ("ppref24", "bzero"): "no_run",
    ("ppref24", "bs"):    "no_run",

    # PbPb 2023 (official: all)
    ("pbpb23", "bplus"): "no_run",
    ("pbpb23", "bzero"): "no_run",
    ("pbpb23", "bs"):    "no_run",

    # PbPb 2024 (official: defined in McM, not produced yet)
    ("pbpb24", "bplus"): "no_run",
    ("pbpb24", "bzero"): "no_run",
    ("pbpb24", "bs"):    "no_run",

    # PbPb 2025 (no official) -> submit from CMSSW_15_1_X
    ("pbpb25", "bplus"): "no_run",
    ("pbpb25", "bzero"): "no_run",
    ("pbpb25", "bs"):    "no_run",
}


def build_tasks():
    from mc_crab_common import CAMPAIGNS

    tasks, problems = [], []
    for key, mode in MODES.items():
        if mode == "no_run":
            continue
        campaign, channel = key
        if mode == "official":
            sample = OFFICIAL_SAMPLES.get(key)
            if sample is None:
                problems.append(f"{key}: no official sample (use 'private' or 'no_run')")
                continue
            processing = sample.get("processing", CAMPAIGNS[campaign]["official_processing"])
            inputs = {pt: f"/{sample['primary'].format(pthat=pt)}/{processing}/MINIAODSIM" for pt in PTHAT_BINS}
        else:
            if key not in PRIVATE_SAMPLES:
                problems.append(f"{key}: no private sample defined in PRIVATE_SAMPLES")
                continue
            inputs = private_inputs(PRIVATE_SAMPLES[key])
        for pthat, dataset in inputs.items():
            base_name = f"{DECAY_NAMES[channel]}_pthat{pthat}_Bfinder"
            tasks.append(make_task(ANALYSIS, campaign, mode, pthat, base_name, dataset, BFINDER_CHANNEL_SWITCHES[channel]))
    return tasks, problems


if __name__ == "__main__":
    check_modes(MODES)
    main(ANALYSIS, *build_tasks())
