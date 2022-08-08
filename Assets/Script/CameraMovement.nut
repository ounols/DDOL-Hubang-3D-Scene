class CameraMovement extends CSEngineScript {

    myTransform = null;
    gameMgr = null;
    camera = null;

    function Init() {
        camera = gameObject.GetComponent<CameraComponent>();
        local game_manager_obj = gameObject.Find("game manager");
        gameMgr = game_manager_obj.GetClass<GameManagerScript>();
        myTransform = gameObject.GetTransform();
    }

    function Tick(elapsedTime) {
        local value = gameMgr.sBpmLerp;
        local rotate = vec3();
        rotate.Set(0, 1, 0);
        camera.SetPerspective(40 + fabs(sin(value * PI)) * 2, 0.0001, 9999);
        myTransform.rotation = Quaternion.AngleAxis(rotate, elapsedTime / 800.0);
    }
}