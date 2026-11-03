#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern const float lbl_27_rodata_642C;

struct Owner { char pad[0x60]; soModuleAccesser* accesser; };

extern "C" void fn_27_2E972C(Owner* obj) {
    float s = obj->accesser->getPostureModule().getScale();
    Vec3f pos = obj->accesser->getPostureModule().getPos();
    obj->accesser->getPostureModule().getLr();
    Vec3f rot;
    Vec3f scale;
    scale.m_x = s;
    scale.m_y = s;
    rot.m_x = lbl_27_rodata_642C;
    rot.m_y = lbl_27_rodata_642C;
    rot.m_z = lbl_27_rodata_642C;
    scale.m_z = s;
    obj->accesser->getModelModule().setNodeSRT(0, &scale, &rot, &pos);
}
