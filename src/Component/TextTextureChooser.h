#pragma once

#include <Component/SComponent.h>

class GameManagerComponent;
namespace CSE {
    class STexture;
    class SMaterial;
}

class TextTextureChooser : public CSE::SComponent {
public:
    COMPONENT_DEFINE_CONSTRUCTOR(TextTextureChooser);
    ~TextTextureChooser() override;

    void Init() override;

    void Tick(float elapsedTime) override;

    void Exterminate() override;

    void SetGameManagerComponent(GameManagerComponent* gmc);

    void SetMaterials(CSE::SMaterial* material);

private:
    CSE::SMaterial* m_material = nullptr;
    GameManagerComponent* m_gameManagerComponent = nullptr;
};
