#include <nw4r/math/math_types.h>

#pragma force_active off
namespace {
#define PSVECScale LocalScale
#define PSVECNormalize LocalNormalize
#define PSVECAdd LocalAdd
#define PSVECDotProduct LocalDot
#include <../src/revolution/MTX/vec.c>
#undef PSVECDotProduct
#undef PSVECAdd
#undef PSVECNormalize
#undef PSVECScale
}
#pragma force_active on

using namespace nw4r::math;

struct Node {
    char pad0[0x34];
    VEC3 pos;
    VEC3 oldPos;
    char pad4C[0x80 - 0x4C];
    float length;
    char pad84[0xDC - 0x84];
    MTX34 matrix;
    char pad10C[0x16C - 0x10C];
    MTX34 relative;
};

struct State {
    Node** nodes;
    int count;
    char pad8[0x42 - 8];
    unsigned char updated;
    unsigned char skipped;
};

inline int remaining(State* self) {
    int skip = self->skipped;
    return reinterpret_cast<int*>(self)[1] - skip;
}

extern "C" {
void fn_801EC158(MTX34*);
void fn_8003DE70(VEC3*);
void fn_801EC868(const MTX34*, MTX34*, float, float, float);
void fn_801EC41C(const MTX34*, MTX34*);
void fn_801EC1B8(const MTX34*, const MTX34*, MTX34*);

void fn_80091AFC(State* self) {
    MTX34 identity;
    MTX34 result;
    MTX34 current;
    MTX34 previous;
    MTX34 inverse;
    MTX34 base;
    VEC3 direction;

    fn_801EC158(&identity);
    self->nodes[0]->relative = identity;
    base = self->nodes[0]->matrix;
    direction = self->nodes[0]->pos - self->nodes[0]->oldPos;
    fn_8003DE70(&direction);

    int i = 1;
    if (remaining(self) > 1) {
        for (; i < remaining(self); ++i) {
            VEC3 delta;
            LocalScale((const Vec*)&direction, (Vec*)&delta,
                       self->nodes[i]->length);
            self->nodes[i]->oldPos = self->nodes[i - 1]->pos;
            self->nodes[i]->pos = self->nodes[i]->oldPos + delta;
            delta = self->nodes[i]->oldPos - self->nodes[0]->oldPos;
            fn_801EC868(&base, &result, delta.x, delta.y, delta.z);
            self->nodes[i]->matrix = result;

            previous = self->nodes[i - 1]->matrix;
            fn_801EC41C(&previous, &inverse);
            current = self->nodes[i]->matrix;
            fn_801EC1B8(&inverse, &current, &result);
            self->nodes[i]->relative = result;
        }
    }

    self->updated = reinterpret_cast<int*>(self)[1];
    self->skipped = reinterpret_cast<int*>(self)[1];
}
}
