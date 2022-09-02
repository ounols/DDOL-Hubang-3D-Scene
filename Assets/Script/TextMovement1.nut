class TextMovement1 extends CSEngineScript {

    myTransform = null;
    gameMgr = null;
    cameraTargetObject = null;

    index = 0;
    textScale = 0.13;

    startPart = 32;

    function Init() {
        local game_manager_obj = gameObject.Find("game manager");
        gameMgr = game_manager_obj.GetClass<GameManagerScript>();
        myTransform = gameObject.GetTransform();
    }

    function Tick(elapsedTime) {
        if(gameMgr.sBpmPart < startPart) {
            return;
        }

        local value = gameMgr.sBpmLerp;

        if(gameMgr.sBpmPart < startPart + 4) {
            local nextPart = startPart + 4;
            if(index == 1)
                Text_1(value / 4 + (4 + gameMgr.sBpmPart - nextPart) * 0.25);
            else if(gameMgr.sBpmPart > startPart) {
                Text_2(value / 3 + (3 + gameMgr.sBpmPart - nextPart) * 0.33);
            }
            return;
        }
        else if (gameMgr.sBpmPart < startPart + 16) {
            local scl = vec3();
            scl.Set(0, 0, 0);
            myTransform.scale = scl;
            return;
        }

        startPart = gameMgr.sBpmPart;
        Tick(elapsedTime);
    }

    function Text_1(value) {
        local pos = vec3();
        local scl = vec3();
        local v = pow(value, 0.1) + pow(value, 14) - 0.4;
        local vs= pow(value, 0.3) * textScale;

        pos.Set(0, 0.2 * v, 0.01 + 0.5 * v);
        scl.Set(2 * vs, vs, vs);

        myTransform.position = pos;
        myTransform.scale = scl;
    }

    function Text_2(value) {
        local pos = vec3();
        local scl = vec3();
        local v = pow(value, 0.1) + pow(value, 14) - 0.4;
        local vs= pow(value, 0.3) * textScale;

        pos.Set(0, -0.3 * v, 0.01 + 0.7 * v);
        scl.Set(2 * vs, vs, vs);

        myTransform.position = pos;
        myTransform.scale = scl;
    }
}