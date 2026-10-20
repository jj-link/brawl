#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
unsigned int fn_107_13FB4(void*, soModuleAccesser*, Vec3f*);
unsigned int fn_107_140F4(void*, soModuleAccesser*, Vec3f*, Vec2f*);
extern const float lbl_107_rodata_C4;
extern const float lbl_107_rodata_C8;
}

extern "C" void fn_107_141A0(void* process, soModuleAccesser* accesser) {
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x12f:
        accesser->getStatusModule().getPrevStatusKind(0);
        break;
    case 0x12d: {
        int areaId = accesser->getAreaModule().getEnviromentElementChecker()->getWaterAreaId();
        accesser->getWorkManageModule().setInt(areaId, 0x20000002);

        Vec3f point;
        if (fn_107_13FB4(process, accesser, &point) == 1) {
            Vec2f result;
            if (fn_107_140F4(process, accesser, &point, &result) == 1) {
                Vec3f position;
                Vec3f rotation;
                rotation.m_x = lbl_107_rodata_C4;
                rotation.m_y = lbl_107_rodata_C4;
                rotation.m_z = lbl_107_rodata_C4;
                position.m_x = result.m_x;
                position.m_y = result.m_y;
                position.m_z = lbl_107_rodata_C4;
                accesser->getEffectModule().req(
                    (EfID)8, &position, &rotation, lbl_107_rodata_C8, 0, -1);
            }
        }
        accesser->getAreaModule().setAreaShapeType(
            3, soAreaInstance::Shape_Rectangle_Ref_Ground_Rhombus);
        break;
    }
    }
}
