#include <so/so_module_accesser.h>
#include <cm/cm_camera_controller.h>
#pragma force_active on

extern "C" {
extern const float lbl_115_rodata_C8;
extern const char lbl_115_data_7524[], lbl_115_data_7444[], lbl_115_data_2760[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_115_8EF8(Vec3f*, float, float, float);
void fn_115_C8BC(float* dst, const float* src);
void fn_27_195F7C(soModuleAccesser*, Vec3f*);
CameraController* getInstance__16CameraControllerFv();
}

extern "C" void fn_115_11D60(void*, soModuleAccesser* accesser) {
    Vec3f pos = accesser->getModelModule().getNodeGlobalPosition(6, false);
    int water;
    if (accesser->getAreaModule().getEnviromentElementChecker()->testWater(
            reinterpret_cast<Vec2f*>(&pos), &water) == true) {
        if (!accesser->getWorkManageModule().isFlag(0x22000017)) {
            if (accesser->getWorkManageModule().getInt(0x10000027) == 0) {
                fn_27_195F7C(accesser, fn_115_8EF8(&Vec3f(), pos.m_x,
                    *reinterpret_cast<float*>(&water), pos.m_y));
                char* energy = static_cast<char*>(__dynamic_cast(
                    accesser->getKineticModule().getEnergy(3), 0,
                    lbl_115_data_7444, lbl_115_data_2760, 1));
                float speed[2];
                speed[0] = lbl_115_rodata_C8;
                speed[1] = lbl_115_rodata_C8;
                fn_115_C8BC(reinterpret_cast<float*>(energy + 8), speed);
                accesser->getWorkManageModule().setInt(0x1e, 0x10000027);
            }
        }
        accesser->getWorkManageModule().onFlag(0x22000017);
    } else {
        accesser->getWorkManageModule().offFlag(0x22000017);
    }
    if (accesser->getGroundModule().isTouch(static_cast<grCollStatus::TouchMask>(8), 0)) {
        char* energy = static_cast<char*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(1), 0,
            lbl_115_data_7524, lbl_115_data_2760, 1));
        *reinterpret_cast<float*>(energy + 0xc) = lbl_115_rodata_C8;
    }
    Vec3f position = accesser->getPostureModule().getPos();
    CameraController* camera = getInstance__16CameraControllerFv();
    if (position.m_x < camera->unk158) {
        position.m_x = camera->unk158;
        accesser->getWorkManageModule().offFlag(0x22000018);
    } else if (position.m_x > camera->unk15C) {
        position.m_x = camera->unk15C;
        accesser->getWorkManageModule().offFlag(0x22000019);
    }
    if (position.m_y > camera->unk160) {
        position.m_y = camera->unk160;
    }
    accesser->getPostureModule().setPos(&position);
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x116:
        if (accesser->getWorkManageModule().isFlag(0x22000012)) {
            if (static_cast<u8>(accesser->getGroundModule().getCorrect(0)) == 1) {
                accesser->getGroundModule().setCorrect(static_cast<soGroundShapeImpl::CorrectKind>(5), 0);
            }
            if (accesser->getSituationModule().getKind() == 0) {
                accesser->getSituationModule().setKind(Situation_Air, true);
            }
        }
        break;
    }
}
