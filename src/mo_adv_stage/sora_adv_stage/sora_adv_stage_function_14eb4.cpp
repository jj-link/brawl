#include <gf/gf_camera.h>
#pragma force_active on
extern float lbl_40_rodata_208;
extern float lbl_40_rodata_1F8;
struct CameraBounds {
    float unk0;
    float x;
    float y;
    float width;
    float height;
};
struct CameraController {
    char pad[0xC];
    CameraBounds* bounds;
    char pad10[0x14];
    unsigned char settled;
};
extern "C" void fn_40_14EB4(CameraController* self, Vec3f* out) {
    float dx;
    float x;
    float snapshotY;
    float snapshotX;
    gfCamera* camera = &gfCameraManager::getManager()->m_cameras[0];
    snapshotX = camera->m_targetPos.m_x;
    snapshotY = camera->m_targetPos.m_y;
    float snapshotZ = camera->m_targetPos.m_z;
    Vec3f pos;
    pos.m_x = snapshotX;
    pos.m_y = snapshotY;
    pos.m_z = snapshotZ;
    float cameraX = pos.m_x;
    x = self->bounds->x;
    dx = x - cameraX;
    float halfWidth = self->bounds->width * lbl_40_rodata_208;
    if (dx > halfWidth) {
        out->m_x = x - halfWidth;
    } else if (dx < -halfWidth) {
        out->m_x = x + halfWidth;
    } else {
        out->m_x = cameraX;
    }
    float cameraY = pos.m_y;
    float y = self->bounds->y;
    dx = y - cameraY;
    halfWidth = self->bounds->height * lbl_40_rodata_208;
    if (dx > halfWidth) {
        out->m_y = y - halfWidth;
    } else if (dx < -halfWidth) {
        out->m_y = y + halfWidth;
    } else {
        out->m_y = cameraY;
    }
    if (out->m_x == pos.m_x && out->m_y == pos.m_y) {
        self->settled = 1;
    } else {
        self->settled = 0;
    }
    out->m_z = lbl_40_rodata_1F8;
}
