#include <types.h>
#include <cm/cm_camera_controller.h>

#pragma force_active on

struct CameraThing {
    char pad[0x60];
    float x;
    float y;
    float z;
    char pad6c[0x8e];
    u16 flags;
};

extern "C" CameraController* getInstance__16CameraControllerFv();

extern "C" void fn_800A4200(void* self, const void* pos) {
    CameraController* cc;
    CameraThing* t;
    *(float*)((char*)self + 0x11c) = *(const float*)pos;
    *(float*)((char*)self + 0x120) = *((const float*)pos + 1);
    *(float*)((char*)self + 0x124) = *((const float*)pos + 2);
    cc = getInstance__16CameraControllerFv();
    if ((int)cc->m_currentControllerKind == CameraController::Adventure) {
        t = *(CameraThing**)self;
        t->x = *(float*)((char*)self + 0x11c);
        t->y = *(float*)((char*)self + 0x120);
        t->z = *(float*)((char*)self + 0x124);
        t->flags |= 2;
    }
}
