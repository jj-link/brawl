#include <types.h>
#pragma force_active on

struct Vec3 {
    u32 x;
    u32 y;
    u32 z;
};

struct Ft {
    u32 unk0;
    Vec3 v;
};

extern "C" {
void fn_95_BAC8(Vec3* out, void* self, void* arg);

void* fn_95_BA74(Ft* self, void* arg)
{
    Vec3 tmp;
    fn_95_BAC8(&tmp, self, arg);
    self->v.x = tmp.x;
    self->v.y = tmp.y;
    self->v.z = tmp.z;
    return &self->v;
}
}
