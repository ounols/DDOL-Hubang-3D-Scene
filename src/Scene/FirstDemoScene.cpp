#include <Component/CameraComponent.h>
#include <Object/SPrefab.h>
#include <Component/RenderComponent.h>
#include <Component/LightComponent.h>
#include <Component/CustomComponent.h>
#include "Util/Render/SMaterial.h"
#include "FirstDemoScene.h"

using namespace CSE;

FirstDemoScene::FirstDemoScene() = default;


FirstDemoScene::~FirstDemoScene() = default;


void FirstDemoScene::Init() {
    auto camera = new SGameObject("main camera");
    auto camera_component = camera->CreateComponent<CameraComponent>();
    camera->GetTransform()->m_position = vec3{ 0, 0.2f, 3.f };
//    auto camera_custom_comp = camera->CreateComponent<CustomComponent>();
//    camera_custom_comp->SetClassName("CameraMovement.script");

    auto game_root = new SGameObject("root");


    camera_component->SetTarget(game_root);
}


void FirstDemoScene::Tick(float elapsedTime) {

}


void FirstDemoScene::Destroy() {

}
