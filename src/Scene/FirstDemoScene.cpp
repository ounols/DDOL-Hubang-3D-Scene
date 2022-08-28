#ifdef _WIN32

#include <Windows.h>

#pragma comment(lib, "Winmm.lib")
#endif

#include <Component/CameraComponent.h>
#include <Object/SPrefab.h>
#include <Component/RenderComponent.h>
#include <Component/LightComponent.h>
#include <Component/CustomComponent.h>
#include "Util/Render/SMaterial.h"
#include "FirstDemoScene.h"
#include <Util/AssetsDef.h>
#include <Component/GameManagerComponent.h>
#include <Component/DdolTextureChanger.h>


using namespace CSE;

FirstDemoScene::FirstDemoScene() = default;


FirstDemoScene::~FirstDemoScene() = default;

#ifndef _WIN32
void mciSendString(const char* a, void* b, int c, void* d) {
    std::cout << "Invalid Method in Other OS.\n";
    return;
}
#endif


void FirstDemoScene::Init() {

    auto bgm_str = CSE::NativeAssetsPath() + "part.mp3";
    auto bgm_open_str = "open \"" + bgm_str + "\" type mpegvideo alias mp3";
    mciSendString(bgm_open_str.c_str(), nullptr, 0, nullptr);

    auto camera = new SGameObject("main camera");
    auto camera_component = camera->CreateComponent<CameraComponent>();
    camera->GetTransform()->m_position = vec3{ 0, -0.3f, 0.f };
    auto camera_custom_comp = camera->CreateComponent<CustomComponent>();
    camera_custom_comp->SetClassName("CameraMovement.script");
    camera->CreateComponent<CustomComponent>()->SetClassName("FocusCameraMovement.script");

    auto cameraTarget = new SGameObject("camera target");
    cameraTarget->SetParent(camera);
    cameraTarget->GetTransform()->m_position = vec3{ 0.0f, 0.0f, 0.3f };
    camera_component->SetTarget(cameraTarget);


    auto* game_root = new SGameObject("root");
    auto* game_mgr = new SGameObject("game manager");
    game_mgr->SetParent(game_root);
    m_gameManagerComponent = game_mgr->CreateComponent<GameManagerComponent>();
    const auto& game_mgr_script = game_mgr->CreateComponent<CustomComponent>();
    game_mgr_script->SetClassName("GameManagerScript.script");
    game_mgr_script->SetValue("__variable__", { "bpm", std::to_string(m_bpm), "float" });


    auto* roomPrefab = SResource::Create<SPrefab>("bg.prefab");
    auto* room = roomPrefab->Clone(vec3{ 0, -1.f, 0 }, game_root);

    const auto& room_children = room->GetChildren();
    int index = 0;
    for (const auto& child: room_children) {
        const auto& component = child->GetComponent<RenderComponent>();
        if (component == nullptr) continue;
        component->SetMaterial(SResource::Create<SMaterial>("File:Texture/" + std::to_string(index++) + ".mat"));
    }

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    auto* planePrefab = SResource::Create<SPrefab>("plane_circle.prefab");

    for(int i = 0; i < 16; ++i) {
        auto* ddol_root = new SGameObject("ddol_" + std::to_string(i));
        ddol_root->SetParent(game_root);
        ddol_root->GetTransform()->m_rotation = Quaternion::AngleAxis(vec3{ 0, 1, 0 }, -(Pi / 8) * i);
        ddol_root->CreateComponent<CustomComponent>()->SetClassName("FirstDdolMovement.script");

        auto* plane = planePrefab->Clone(vec3{ 0.02f, -0.2f, 1.5f }, ddol_root);
        plane->SetName("ddol_plane_" + std::to_string(i));
        const float plane_scale = 0.2f;
        plane->GetTransform()->m_scale = vec3{ 2.34f * plane_scale, plane_scale, plane_scale };
        plane->GetTransform()->m_rotation = Quaternion::AngleAxis(vec3{ 0, 1, 0 }, Pi);
        const auto& texChanger = plane->CreateComponent<DdolTextureChanger>();
        texChanger->SetGameManagerComponent(m_gameManagerComponent);

        const auto& plane_children = plane->GetChildren();
        index = 0;
        for (const auto& child: plane_children) {
            const auto& component = child->GetComponent<RenderComponent>();
            if (component == nullptr) continue;
            component->SetMaterial(SResource::Create<SMaterial>("File:Texture/ddol.mat"));
            component->GetMaterial();
            texChanger->SetMaterials(component->GetMaterial());
        }
    }

    {
        SGameObject* direction = new SGameObject();
        direction->SetParent(game_root);
        direction->SetName("directional light 1");
        direction->GetTransform()->m_position = vec3{ 0.f, 1.f, 0.f };
        const auto& light_component = direction->CreateComponent<LightComponent>();
        light_component->SetLightType(LightComponent::DIRECTIONAL);
        light_component->SetDirection(vec4{ 0.0f, 1.0f, 1.0f, 0 });
        light_component->SetShadow(true);

        const auto& light_script = direction->CreateComponent<CustomComponent>();
        light_script->SetClassName("LightController.script");
        light_script->SetValue("__variable__", { "index", "1", "int" });
    }
    {
        SGameObject* direction = new SGameObject();
        direction->SetParent(game_root);
        direction->SetName("directional light 2");
        direction->GetTransform()->m_position = vec3{ 0.f, 1.f, 0.f };
        const auto& light_component = direction->CreateComponent<LightComponent>();
        light_component->SetLightType(LightComponent::DIRECTIONAL);
        light_component->SetDirection(vec4{ 0.0f, 1.0f, -1.0f, 0 });
        light_component->SetShadow(true);

        const auto& light_script = direction->CreateComponent<CustomComponent>();
        light_script->SetClassName("LightController.script");
        light_script->SetValue("__variable__", { "index", "0", "int" });
    }


    m_startClock = std::chrono::system_clock::now();
    mciSendString("play mp3 from 0", nullptr, 0, nullptr);
}


void FirstDemoScene::Tick(float elapsedTime) {
    std::chrono::duration<float> elapsed_seconds = std::chrono::system_clock::now() - m_startClock;
    m_gameManagerComponent->SetTime(m_bpm, elapsed_seconds.count());
}


void FirstDemoScene::Destroy() {

}
