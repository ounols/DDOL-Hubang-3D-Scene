class GameManagerScript extends CSEngineScript {

    sBpmLerp = 0.0;
    sBpmPart = 0;
    bpm = 0.0;

    function Tick(elapsedTime) {
        local bpm_sec = (elapsedTime / 1000.0) / (60.0 / bpm);
        sBpmPart = floor(bpm_sec);
        sBpmLerp = bpm_sec - sBpmPart;
    }
}