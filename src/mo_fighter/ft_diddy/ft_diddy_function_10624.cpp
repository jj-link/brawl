#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" void fn_115_10624(void* unk, soModuleAccesser* accesser, u32 id, float value) {
    Vec3f rot = accesser->m_enumerationStart->m_modelModule->getNodeRotate(id);
    rot.m_x = value;
    accesser->m_enumerationStart->m_modelModule->setNodeRotate(id, &rot);
}
