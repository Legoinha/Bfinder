"""Forest + Bfinder (ntmix channel) over X(3872) / psi(2S) MC, official or private.

Set the mode of each sample in MODES below ("official", "private" or "no_run"), cmsenv in the CMSSW area of
the campaign (PbPb 2025: CMSSW_15_1_X, all others: CMSSW_14_1_X), source crab-setup.sh, then
    python3 Bfinder/FILES/crabConfig_MC.py                 # list what would be submitted (inputs checked in DAS)
    python3 Bfinder/FILES/crabConfig_MC.py --submit        # submit
    python3 Bfinder/FILES/crabConfig_MC.py --pthat 5 10    # only some pThat bins
"""
from mc_crab_common import PTHAT_BINS, check_modes, main, make_task, private_inputs

ANALYSIS = {"work_area": "crab_projects_X", "out_label": "X3872"}
XFINDER_CHANNEL_SWITCHES = (0, 0, 0, 0, 0, 0, 1)

DECAY_NAMES = {
    "x3872": "X3872_to_Jpsi_Rho",
    "x3872_pipi": "X3872_to_Jpsi_pipi",
    "psi2s": "PSI2S_to_Jpsi_pipi",
}

# Official global-DBS samples: primary dataset ({pthat} filled in) and, if different from the campaign
# default, the processing string.
OFFICIAL_SAMPLES = {
    ("pbpb23", "prompt", "x3872"): {"primary": "PromptX3872ToJPsiRho_pThat-{pthat}_TuneCP5_5p36TeV_pythia8"},
    ("pbpb23", "nonprompt", "x3872"): {"primary": "NonpromptX3872ToJPsiRho_pThat-{pthat}_TuneCP5_5p36TeV_pythia8"},
    ("pbpb23", "prompt", "x3872_pipi"): {"primary": "PromptX3872ToJPsiPiPi_pThat-{pthat}_TuneCP5_5p36TeV_pythia8-evtgen"},
    ("pbpb23", "prompt", "psi2s"): {"primary": "PromptPsi2SToJPsiPiPi_pThat-{pthat}_TuneCP5_5p36TeV_pythia8-evtgen"},
    ("pbpb23", "nonprompt", "psi2s"): {"primary": "NonpromptPsi2SToJPsiPiPi_pThat-{pthat}_TuneCP5_5p36TeV_pythia8-evtgen"},
    ("ppref24", "prompt", "psi2s"): {"primary": "PromptPsi2SToJPsiPiPi_pThat-{pthat}_TuneCP5_5p36TeV_pythia8-evtgen"},
    ("ppref24", "nonprompt", "psi2s"): {"primary": "NonpromptPsi2SToJPsiPiPi_pThat-{pthat}_TuneCP5_5p36TeV_pythia8-evtgen"},
    ("ppref24", "prompt", "x3872_pipi"): {
        "primary": "PromptX3872ToJPsiPiPi_pThat-{pthat}_TuneCP5_5p36TeV_pythia8-evtgen",
        "processing": "RunIIIpp5p36Winter24MiniAOD-141X_mcRun3_2024_realistic_ppRef5TeV_v7-v1",
    },
}

# Private MiniAOD in phys03: a pattern with {pthat} (a '*' is resolved in DAS, e.g. the publication hash),
# or an explicit {pthat: dataset} dict for older single-pThat samples.
PRIVATE_SAMPLES = {
    ("pbpb25", "prompt", "x3872"):
        "/X3872ToJpsiRho_prompt_pthat{pthat}_TuneCP5_5p36TeV_pythia8_HydjetCELLO/hmarques-MC_PbPb2025_151X_MINIAOD_v1-*/USER",
    ("pbpb25", "nonprompt", "x3872"):
        "/X3872ToJpsiRho_nonprompt_pthat{pthat}_TuneCP5_5p36TeV_pythia8_HydjetCELLO/hmarques-MC_PbPb2025_151X_MINIAOD_v1-*/USER",
    ("pbpb25", "prompt", "psi2s"):
        "/Psi2SToJpsiPiPi_prompt_pthat{pthat}_TuneCP5_5p36TeV_pythia8_HydjetCELLO/hmarques-MC_PbPb2025_151X_MINIAOD_v1-*/USER",
    ("pbpb25", "nonprompt", "psi2s"):
        "/Psi2SToJpsiPiPi_nonprompt_pthat{pthat}_TuneCP5_5p36TeV_pythia8_HydjetCELLO/hmarques-MC_PbPb2025_151X_MINIAOD_v1-*/USER",
    # older single-pThat ppRef samples
    ("ppref24", "prompt", "x3872"): {
        10: "/MC_ppRef_X/hmarques-X3872_prompt_to_JPsiRho_pthat10_miniAOD-6f03abc0b379285456b22033b16cec86/USER",
    },
    ("ppref24", "nonprompt", "x3872"): {
        5: "/ppRef_X3872/hmarques-nonprompt_X3872_to_Jpsi_Rho_phat5_miniAOD-b08ea5aba0caf44286efb8557bf5e709/USER",
    },
}


######################################################################################################################################################
###################################          MODES: "official" | "private" | "no_run"          ###################################
######################################################################################################################################################

MODES = {
    # ppRef 2024 (official: psi2S, X->J/psi pipi prompt; private: X->J/psi rho)
    ("ppref24", "prompt",    "x3872"):      "no_run",
    ("ppref24", "nonprompt", "x3872"):      "no_run",
    ("ppref24", "prompt",    "x3872_pipi"): "no_run",
    ("ppref24", "prompt",    "psi2s"):      "no_run",
    ("ppref24", "nonprompt", "psi2s"):      "no_run",

    # PbPb 2023 (official: all)
    ("pbpb23", "prompt",    "x3872"):      "no_run",
    ("pbpb23", "nonprompt", "x3872"):      "no_run",
    ("pbpb23", "prompt",    "x3872_pipi"): "no_run",
    ("pbpb23", "prompt",    "psi2s"):      "no_run",
    ("pbpb23", "nonprompt", "psi2s"):      "no_run",

    # PbPb 2024 (no official; private production to come)
    ("pbpb24", "prompt",    "x3872"):      "no_run",
    ("pbpb24", "nonprompt", "x3872"):      "no_run",
    ("pbpb24", "prompt",    "psi2s"):      "no_run",
    ("pbpb24", "nonprompt", "psi2s"):      "no_run",

    # PbPb 2025 (no official; private: MC_PbPb2025_151X_MINIAOD_v1) -> submit from CMSSW_15_1_X
    ("pbpb25", "prompt",    "x3872"):      "private",
    ("pbpb25", "nonprompt", "x3872"):      "private",
    ("pbpb25", "prompt",    "psi2s"):      "private",
    ("pbpb25", "nonprompt", "psi2s"):      "private",
}


def build_tasks():
    from mc_crab_common import CAMPAIGNS

    tasks, problems = [], []
    for key, mode in MODES.items():
        if mode == "no_run":
            continue
        campaign, production, decay = key
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
            base_name = f"{production}_{DECAY_NAMES[decay]}_phat{pthat}_Bfinder"
            tasks.append(make_task(ANALYSIS, campaign, mode, pthat, base_name, dataset, XFINDER_CHANNEL_SWITCHES))
    return tasks, problems


if __name__ == "__main__":
    check_modes(MODES)
    main(ANALYSIS, *build_tasks())
