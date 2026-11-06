#include <gf/gf_camera.h>
#pragma force_active on
extern "C" void fn_80018778(gfCamera*);
extern "C" void fn_27_239AF4(void* self, Vec3f* a, Vec3f* b, float x, float y) {
    gfCameraManager* manager = gfCameraManager::getManager();
    if (manager && (a->m_x != b->m_x || a->m_y != b->m_y || a->m_z != b->m_z)) {
        gfCamera* cam = &manager->m_cameras[0];
        cam->m_transformFlag.m_mask = 0x43;
        cam->m_centerPos.m_x = a->m_x;
        cam->m_centerPos.m_y = a->m_y;
        cam->m_centerPos.m_z = a->m_z;
        cam->m_targetPos.m_x = b->m_x;
        cam->m_targetPos.m_y = b->m_y;
        cam->m_targetPos.m_z = b->m_z;
        unsigned short mask = cam->unkFA.m_mask;
        cam->m_rot.m_z = x;
        cam->unkFA.m_mask = mask | 0x42;
        *(float*)cam->_0xD4 = y;
        fn_80018778(cam);
    }
}