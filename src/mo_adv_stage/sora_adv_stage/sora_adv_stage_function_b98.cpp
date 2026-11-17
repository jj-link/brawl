#include <gf/gf_camera.h>
#include <cm/cm_camera_controller.h>

#pragma force_active on

extern "C" {
void fn_80018778(gfCamera*);
void fn_40_5D44(void*);
void fn_800A4BA8(void*, void*);
void fn_800A5990(void*, float*);
void* __dynamic_cast(void*, long, const void*, const void*, short);

extern const char lbl_40_data_1590[];
extern const char lbl_40_data_15D8[];
}

struct Constants {
    char pad[0x2c];
    float zero, a, b, c, d, e, f, g, h;
};

extern const Constants lbl_40_rodata_0;

struct V3 {
    float x, y, z;
};

struct V4 {
    float x, y, z, w;
};

struct Stage {
    char pad[0x1c0];
    char* data;
    char pad2[4];
    char* data2;
};

extern "C" void fn_40_B98(Stage* self)
{
    V3 center = {lbl_40_rodata_0.zero, lbl_40_rodata_0.e, lbl_40_rodata_0.f};
    V3 target = {lbl_40_rodata_0.zero, lbl_40_rodata_0.g, lbl_40_rodata_0.zero};

    gfCamera* cam = (gfCamera*)gfCameraManager::getManager();
    cam->m_transformFlag.m_mask = 0x43;
    float t1 = center.x;
    cam->m_centerPos.m_x = t1;
    float t2 = center.y;
    cam->m_centerPos.m_y = t2;
    float t3 = center.z;
    cam->m_centerPos.m_z = t3;
    float t4 = target.x;
    cam->m_targetPos.m_x = t4;
    float t5 = target.y;
    cam->m_targetPos.m_y = t5;
    float h = lbl_40_rodata_0.h;
    float t6 = target.z;
    cam->m_targetPos.m_z = t6;
    cam->unkFA.m_mask |= 2;
    cam->unkD0 = h;
    fn_80018778(cam);

    fn_40_5D44(self);

    char* p = (char*)__dynamic_cast(
        *(void**)((char*)CameraController::getInstance() + 0x48),
        4, lbl_40_data_1590, lbl_40_data_15D8, 0);

    if (p && self->data2) {
        fn_800A4BA8(p, self->data2 + 8);
    }

    if (p && self->data) {
        *(float*)(p + 0xdc) = *(float*)(self->data + 4);
        fn_800A5990(p, (float*)(self->data + 8));

        float fw, fz, fy, fx;
        fy = *(float*)(self->data + 0x10);
        fx = *(float*)(self->data + 0xc);
        fw = *(float*)(self->data + 0x18);
        fz = *(float*)(self->data + 0x14);
        V4 v = {fx, fy, fz, fw};
        *(float*)(p + 0xe8) = v.x;
        *(float*)(p + 0xec) = v.y;
        *(float*)(p + 0xf0) = v.z;
        *(float*)(p + 0xf4) = v.w;
    }
}
