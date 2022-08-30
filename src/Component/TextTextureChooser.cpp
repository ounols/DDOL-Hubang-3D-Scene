#include "TextTextureChooser.h"
#include "GameManagerComponent.h"
#include <Util/Render/SMaterial.h>
#include <Util/Render/STexture.h>

using namespace CSE;

COMPONENT_CONSTRUCTOR(TextTextureChooser) {

}

void TextTextureChooser::Init() {

}

void TextTextureChooser::Tick(float elapsedTime) {

}

void TextTextureChooser::Exterminate() {

}

TextTextureChooser::~TextTextureChooser() = default;

void TextTextureChooser::SetGameManagerComponent(GameManagerComponent* gmc) {
    m_gameManagerComponent = gmc;
}

void TextTextureChooser::SetMaterials(CSE::SMaterial* material) {
    m_material = material;
}