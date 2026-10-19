#pragma force_active on
struct Vec3 {
    float x;
    float y;
    float z;
};

struct Obj {
    char pad[0x1a4];
    Vec3 pos;
};

extern "C" {
void fn_67_B094(Obj *self, Vec3 *out)
{
    if (out != 0) {
        out->x = self->pos.x;
        out->y = self->pos.y;
        out->z = self->pos.z;
    }
}
}
