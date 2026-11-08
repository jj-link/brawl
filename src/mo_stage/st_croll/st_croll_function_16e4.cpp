#include <gf/gf_camera.h>
#include <cm/cm_controller_ai.h>
#pragma force_active on

extern "C" void fn_80196530(void*, float*, float);
extern "C" void fn_80018778(gfCamera*);
extern "C" {
extern const float lbl_90_rodata_0;
extern const float lbl_90_rodata_10;
extern const float lbl_90_rodata_34;
}

extern "C" void fn_90_16E4(char* self) {
    float data[13];
    gfCamera* cam = (gfCamera*)gfCameraManager::getManager();
    ((unsigned char*)g_cmAIController)[0x94] &= ~0x10;
    if (cam && *(void**)(self + 0x1dc)) {
        fn_80196530(self + 0x1dc, data, lbl_90_rodata_0);
        if (!(*(unsigned int*)((char*)*(void**)(self + 0x1dc) + 0x18) & 1)) {
            cam->m_transformFlag.m_mask = 0x22;
            Vec2f v;
            v.m_x = data[8];
            v.m_y = data[9];
            cam->m_rot.m_x = v.m_x;
            cam->m_rot.m_y = v.m_y;
        } else {
            cam->m_transformFlag.m_mask = 0x43;
            cam->m_targetPos.m_x = data[8];
            cam->m_targetPos.m_y = data[9];
            cam->m_targetPos.m_z = data[10];
            cam->unkFA.m_mask |= 2;
            cam->m_rot.m_z = -data[11];
            cam->unkFA.m_mask |= 0x40;
        }
        cam->m_centerPos.m_x = data[2];
        cam->m_centerPos.m_y = data[3];
        cam->m_centerPos.m_z = data[4];
        cam->m_near = data[6];
        cam->m_far = data[7];
        cam->unkD0 = lbl_90_rodata_34 * data[12];
        *(float*)((char*)cam + 0xd4) = lbl_90_rodata_10;
        fn_80018778(cam);
    }
}