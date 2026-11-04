#include <so/so_module_accesser.h>
#include <so/effect/so_effect_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/posture/so_posture_module_simple.h>
#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_27_1DA030();

struct Owner {
    char pad[0x60];
    soModuleAccesser* accesser;
    char pad2[0x9e8 - 0x64];
    int node;
};

extern "C" void fn_27_1E4254(Owner* self) {
    fn_27_1DA030();
    self->accesser->m_enumerationStart->m_workManageModule->getInt(0x10000005);
    Vec3f pos = self->accesser->getPostureModule().getPos();
    float s = self->accesser->getPostureModule().getScale();
    self->accesser->m_enumerationStart->m_effectModule->setPos(self->node, &pos);
    Vec3f scale;
    scale.m_x = s;
    scale.m_y = s;
    scale.m_z = s;
    self->accesser->m_enumerationStart->m_effectModule->setScale(self->node, &scale);
}
