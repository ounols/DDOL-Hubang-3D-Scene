#pragma once
#include "Manager/Base/Scene.h"
#include "Object/SGameObject.h"
#include "Util/Render/MeshSurface.h"

#include <iostream>
#include <chrono>
#include <ctime>

class GameManagerComponent;

class FirstDemoScene : public CSE::Scene {
public:
    FirstDemoScene();
    ~FirstDemoScene() override;

    void Init() override;
    void Tick(float elapsedTime) override;
    void Destroy() override;

private:
    void GenerateTextArea(CSE::SGameObject* root);
    static const CSE::RenderComponent* SetMaterialInGameObject(CSE::SGameObject* obj, CSE::SMaterial* mat);

private:
    std::chrono::time_point<std::chrono::system_clock> m_startClock;
    unsigned short m_bpm = 200;
    GameManagerComponent* m_gameManagerComponent = nullptr;

    CSE::SPrefab* m_planePrefab = nullptr;
};