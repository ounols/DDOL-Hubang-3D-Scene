#pragma once

#include <Component/SComponent.h>

class GameManagerComponent : public CSE::SComponent {
public:
    GameManagerComponent();

    ~GameManagerComponent() override;

    void Init() override;

    void Tick(float elapsedTime) override;
    void SetTime(unsigned short bpm, float elapsedSeconds);

    void Exterminate() override;

    static float GetBPMLerp() {
        return m_sBpmLerp;
    }

private:
    static float m_sBpmLerp;
};
