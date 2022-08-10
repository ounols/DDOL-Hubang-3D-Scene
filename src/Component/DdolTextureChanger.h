#pragma once

#include <Component/SComponent.h>

class GameManagerComponent;
namespace CSE {
    class STexture;
    class SMaterial;
}

class DdolTextureChanger : public CSE::SComponent {
public:
    DdolTextureChanger();

    ~DdolTextureChanger() override;

    void Init() override;

    void Tick(float elapsedTime) override;

    void Exterminate() override;

    void SetGameManagerComponent(GameManagerComponent* gmc);

    void SetMaterials(CSE::SMaterial* material);

private:
    unsigned short m_texCount = 22;
    GameManagerComponent* m_gameManagerComponent = nullptr;

    std::vector<CSE::STexture*> m_albedoTextures;
    std::vector<CSE::STexture*> m_normalTextures;
    CSE::SMaterial* m_material = nullptr;
};
