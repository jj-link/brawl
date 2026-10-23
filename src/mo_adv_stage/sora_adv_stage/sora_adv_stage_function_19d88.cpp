#include <types.h>
#pragma force_active on

struct Vec3f {
    float x, y, z;
};

extern "C" void* getManager__15gfCameraManagerFv();
extern "C" void SetTranslate__Q34nw4r3g3d7ResNodeFfff(void*, float, float, float);

struct Self {
    char pad0[4];
    u8 b4;
    char pad5[7];
    void* node;
    char pad10[4];
    Vec3f base;
    Vec3f offset;
    float sx, sy;
};

extern "C" void fn_40_19D88(Self* self) {
    if (self->b4 != 0 && self->node != 0) {
        char* cam = (char*)getManager__15gfCameraManagerFv();
        if (cam != 0) {
            Vec3f camPos;
            camPos.x = *(float*)(cam + 0x6c);
            camPos.y = *(float*)(cam + 0x70);
            camPos.z = *(float*)(cam + 0x74);

            Vec3f pos;
            pos.x = self->base.x;
            pos.y = self->base.y;
            pos.z = self->base.z;
            pos.x += camPos.x * self->sx - self->offset.x;
            pos.y += camPos.y * self->sy - self->offset.y;
            pos.z -= self->offset.z;

            SetTranslate__Q34nw4r3g3d7ResNodeFfff(
                &self->node, pos.x, pos.y, pos.z);
        }
    }
}
