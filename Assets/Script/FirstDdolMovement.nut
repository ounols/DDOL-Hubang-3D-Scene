class FirstDdolMovement extends CSEngineScript {

    myTransform = null;
    gameMgr = null;

    function Init() {
        local game_manager_obj = gameObject.Find("game manager");
        gameMgr = game_manager_obj.GetClass<GameManagerScript>();
        myTransform = gameObject.GetTransform();
    }

    function Tick(elapsedTime) {
        local value = gameMgr.sBpmLerp;
        local pos = vec3();
        pos.Set(0, -0.05 * (1 - fabs(sin(value * PI))), 0);
        //camera.SetPerspective(40 + fabs(sin(value * PI)) * 2, 0.0001, 9999);
        myTransform.position = pos;
    }
}