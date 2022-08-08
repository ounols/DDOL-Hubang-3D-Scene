//
// Created by ounol on 2022-08-09.
//

#include <iostream>
#include "GameManagerComponent.h"

using namespace CSE;
float GameManagerComponent::m_sBpmLerp = 0.f;

COMPONENT_CONSTRUCTOR(GameManagerComponent) {

}

GameManagerComponent::~GameManagerComponent() = default;

void GameManagerComponent::Init() {

}

void GameManagerComponent::Tick(float elapsedTime) {

}

void GameManagerComponent::Exterminate() {

}

void GameManagerComponent::SetTime(unsigned short bpm, float elapsedSeconds) {
    auto bpm_sec = elapsedSeconds / (60.0f / bpm);
    m_sBpmLerp = bpm_sec - static_cast<int>(bpm_sec);
}
