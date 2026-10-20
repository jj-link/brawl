#include <types.h>
#include <so/so_null.h>
#pragma force_active on

struct Vec3f {
    float x, y, z;
};

struct Work {
    int unk0;
    char pad[4];
    Vec3f pos;
};

class Inner : public soNullable {
public:
    virtual Work* getWork(u32 arg);
};

class Outer {
public:
    char pad[0x30];
    Inner* unk30;
};

extern "C" bool fn_27_3AD40(Outer* self, u32 arg, Vec3f* vec) {
    if (self->unk30->getWork(arg)->unk0 == 0) {
        return false;
    }
    Work* work = self->unk30->getWork(arg);
    work->pos.x = vec->x;
    work->pos.y = vec->y;
    work->pos.z = vec->z;
    return true;
}
