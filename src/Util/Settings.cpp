//
// Created by ounol on 2021-08-14.
//

#include "Settings.h"

using namespace CSE;

const char* Settings::m_deferredGeometryPassShaderID = "File:Shader/PBR/PBR-Geometry-Pass.shader";
const char* Settings::m_defaultForwardMaterialID = "File:Global Material/DefaultPBR.mat";
const char* Settings::m_defaultDeferredMaterialID = "File:Global Material/Default.mat";
const char* Settings::m_defaultDeferredProxyMaterialID = "File:Global Material/DefaultPBR.mat";
const char* Settings::m_defaultMainBufferShaderID = "File:Shader/Main-Buffer.shader";
const char* Settings::m_defaultBlitBufferShaderID = "File:Shader/Blit-Buffer.shader";
const int Settings::m_maxLights = 8;

const bool Settings::m_assetsPacked = false;

const int Settings::m_maxJoints = 1;

Settings::Settings() = default;

Settings::~Settings() = default;

const char* Settings::GetDeferredGeometryPassShaderID() {
    return m_deferredGeometryPassShaderID;
}

const char* Settings::GetDefaultForwardMaterialId() {
    return m_defaultForwardMaterialID;
}

const char* Settings::GetDefaultDeferredMaterialId() {
#if 1
    return m_defaultDeferredProxyMaterialID;
#else
    return m_defaultDeferredMaterialID;
#endif
}

const char* Settings::GetDefaultMainBufferShaderID() {
    return m_defaultMainBufferShaderID;
}

const char* Settings::GetDefaultBlitBufferShaderID() {
    return m_defaultBlitBufferShaderID;
}

int Settings::GetMaxLights() {
    return m_maxLights;
}

int Settings::GetMaxJoints() {
    return m_maxJoints;
}