//
// Created by ounol on 2022-08-11.
//

#include "DdolTextureChanger.h"
#include "GameManagerComponent.h"
#include <Util/Render/SMaterial.h>
#include <Util/Render/STexture.h>

using namespace CSE;

COMPONENT_CONSTRUCTOR(DdolTextureChanger) {

}

DdolTextureChanger::~DdolTextureChanger() = default;

void DdolTextureChanger::Init() {
    m_albedoTextures.reserve(m_texCount);
    m_normalTextures.reserve(m_texCount);
    for (unsigned short i = 0; i < m_texCount; ++i) {
        m_albedoTextures.push_back(
                SResource::Create<STexture>("File:Texture/albedo/ddol-albedo" + std::to_string(i) + ".png"));
        m_normalTextures.push_back(
                SResource::Create<STexture>("File:Texture/normal/ddol-normal" + std::to_string(i) + ".png"));

        m_material->SetTexture("texture.albedo", m_albedoTextures.back());
        m_material->SetTexture("texture.normal", m_normalTextures.back());
        m_material->AttachElement(); // 프리 로딩
    }
}

void DdolTextureChanger::Tick(float elapsedTime) {
    int index = m_texCount * m_gameManagerComponent->GetBPMLerp();
    m_material->SetTexture("texture.albedo", m_albedoTextures[index]);
    m_material->SetTexture("texture.normal", m_normalTextures[index]);
}

void DdolTextureChanger::Exterminate() {

}

void DdolTextureChanger::SetGameManagerComponent(GameManagerComponent* gmc) {
    m_gameManagerComponent = gmc;
}

void DdolTextureChanger::SetMaterials(CSE::SMaterial* material) {
    m_material = material;
}
