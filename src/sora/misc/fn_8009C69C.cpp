#include <types.h>
#include <cm/cm_camera_controller.h>
#include <gf/gf_camera.h>

#pragma force_active on

extern "C" {
void fn_8009FCF4(void*, float);
void fn_800A3EE8(void*);
void fn_800A59C4(void*);
void fn_800A6624(void*);
void fn_800A6B78(void*);
void fn_800A6BF0(void*);
void init__21cmMenuFixedControllerFv(void*);
extern const float lbl_805A1DA0;
extern const float lbl_805A1DA8;
}

void CameraController::changeInput(Kind arg) {
    u8* self = (u8*)this;
    int flag;

    if (*(int*)(self + 0x40) == 5) {
        u8* p50 = *(u8**)(self + 0x50);
        if (*(int*)(p50 + 0x20) == 0)
            return;
    }

    if (*(int*)(self + 0x40) == 7 && arg != 7)
        fn_800A6BF0(*(void**)(self + 0x68));

    flag = 1;
    if ((*(int*)(self + 0x40) == 0xD || arg == 0xD) &&
        *(int*)(self + 0x188) > 0)
        flag = 0;

    if (flag != 0 && arg != 0xB && arg != 0xD) {
        u8* m = (u8*)gfCameraManager::getManager();
        if (m != 0) {
            float z = lbl_805A1DA0;
            *(float*)(m + 0x9C) = z;
            *(float*)(m + 0xA0) = z;
            *(float*)(m + 0xA4) = z;
            *(Vec3f*)(m + 0xB4) = Vec3f(z, z, z);
        }
    }

    if (flag != 0 && (arg == 2 || arg == 0xD) &&
        (*(int*)(self + 0x40) == 0xD ||
         *(int*)(self + 0x40) == 0xB))
        fn_8009FCF4(*(void**)(self + 0x58), lbl_805A1DA8);

    m_currentControllerKind = arg;
    *(float*)(self + 0x184) = lbl_805A1DA0;
    m_currentController = getCameraController(arg);

    switch (*(int*)(self + 0x40)) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
        break;
    case 3:
        fn_800A59C4(*(void**)(self + 0x60));
        return;
    case 6:
        fn_800A3EE8(*(void**)(self + 0x54));
        return;
    case 8:
        fn_800A6624(*(void**)(self + 0x6C));
        return;
    case 9:
        init__21cmMenuFixedControllerFv(*(void**)(self + 0x70));
        return;
    case 7:
        fn_800A6B78(*(void**)(self + 0x68));
        break;
    }
}
