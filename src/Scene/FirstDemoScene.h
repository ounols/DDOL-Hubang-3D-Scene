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
    std::chrono::time_point<std::chrono::system_clock> m_startClock;
    unsigned short m_bpm = 200;
    GameManagerComponent* m_gameManagerComponent = nullptr;
};