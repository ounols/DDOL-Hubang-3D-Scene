class FocusCameraMovement extends CSEngineScript {

    myTransform = null;
    gameMgr = null;
    camera = null;
    cameraTargetObject = null;

    startPart = 32;

    function Init() {
        camera = gameObject.GetComponent<CameraComponent>();
        local game_manager_obj = gameObject.Find("game manager");
        gameMgr = game_manager_obj.GetClass<GameManagerScript>();
        myTransform = gameObject.GetTransform();
        cameraTargetObject = gameObject.Find("ddol_plane_0");
    }

    function Tick(elapsedTime) {
        if(gameMgr.sBpmPart < startPart) {
            return;
        }

        if(gameMgr.sBpmPart == startPart) {
            local up_vec = vec3();
            up_vec.Set(0, 1, 0);
            camera.SetUp(up_vec);
            camera.SetTarget(cameraTargetObject);
        }


        local value = gameMgr.sBpmLerp;

        if(gameMgr.sBpmPart < startPart + 4) {
            local nextPart = startPart + 4;
            Movement_1(value / 4 + (4 + gameMgr.sBpmPart - nextPart) * 0.25);
            return;
        }
        else if (gameMgr.sBpmPart < startPart + 8) {
            local nextPart = startPart + 8;
            Movement_2(value / 4 + (4 + gameMgr.sBpmPart - nextPart) * 0.25);
            return;
        }
        else if (gameMgr.sBpmPart < startPart + 12) {
            local nextPart = startPart + 12;
            Movement_3(value / 4 + (4 + gameMgr.sBpmPart - nextPart) * 0.25);
            return;
        }
        else if (gameMgr.sBpmPart < startPart + 16) {
            local nextPart = startPart + 16;
            Movement_4(value / 4 + (4 + gameMgr.sBpmPart - nextPart) * 0.25);
            return;
        }

        startPart = gameMgr.sBpmPart;
        Tick(elapsedTime);
    }

    function Movement_1(value) {
        local up_vec = vec3();
        up_vec.Set(0.5 * value * 0.3, 0.3 * value + 0.5, 0);
        camera.SetUp(up_vec);

        local pos = vec3();
        if(value > 0.9) {
            local v = (value - 0.9) * 10;
            pos.Set(v * - 0.25, -0.3, 0.8 * (1 - v) + 0.5 * v);
        }
        else {
            local v = (value) * 1.1111;
            pos.Set(0, -0.3, 0.5 * v + 0.3);
        }

        myTransform.position = pos;
    }

    function Movement_2(value) {
        local pos = vec3();

        pos.Set(0.5 * value - 0.25, -0.3, value < 0.5 ? 0.5 : 0.7);

        myTransform.position = pos;
    }

    function Movement_3(value) {
        local up_vec = vec3();
        up_vec.Set(0, 1, 0);
        camera.SetUp(up_vec);

        local pos = vec3();

        pos.Set(-0.5 * value + 0.25, -0.3, 0.7 - 0.7 * value);

        myTransform.position = pos;
    }

    function Movement_4(value) {

    }
}