class LightController extends CSEngineScript {

    gameMgr = null;
    light = null;
    index = 0;

    function Init() {
        light = gameObject.GetComponent<LightComponent>();
        local game_manager_obj = gameObject.Find("game manager");
        gameMgr = game_manager_obj.GetClass<GameManagerScript>();
    }

    function Tick(elapsedTime) {
        if(gameMgr.sBpmPart % 2 == index) {
            return;
        }

        local value = 1 - gameMgr.sBpmLerp;
        local color = vec3();
        color.Set(value * (index == 0 ? 30 : 10), value * 10, value * (index == 0 ? 10 : 30));
        light.SetColor(color);
    }
}