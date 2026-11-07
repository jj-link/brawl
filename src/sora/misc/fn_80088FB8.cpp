#include <nw4r/math/math_types.h>
#pragma force_active on
using namespace nw4r::math;
struct A {
    char pad00[0x34];
    VEC3 pos;
    VEC3 prev;
    char pad4c[0x30];
    float radius;
    char pad80[0x38];
    float weight;
};
struct B {
    char pad00[0x74];
    float scale;
    char pad78[4];
    float radius;
    char pad80[0xbc];
    MTX34 matrix;
    char pad16c[0x40];
    VEC3 offset;
    VEC3 pos;
};
extern "C" {
extern const float lbl_805A1BB8;
void fn_801EC158(MTX34*);
void fn_801EC868(const MTX34*, MTX34*, float, float, float);
void fn_801EC1B8(const MTX34*, const MTX34*, MTX34*);
float fn_801ED04C(const VEC3*);
void fn_801ED008(const VEC3*, VEC3*);
int fn_80088FB8(void*, A* a, B* b) {
    int result = 0;
    if (lbl_805A1BB8 != a->weight && b != 0) {
        MTX34 identity, translation, combined;
        fn_801EC158(&identity);
        fn_801EC868(&identity, &translation, b->offset.x, b->offset.y, b->offset.z);
        fn_801EC1B8(&b->matrix, &translation, &combined);
        b->pos.x = combined._03;
        float r1 = b->radius;
        r1 *= b->scale;
        b->pos.y = combined._13;
        b->pos.z = combined._23;
        VEC3 delta = a->pos - a->prev;
        float length = fn_801ED04C(&delta);
        float r2 = a->radius;
        float sum = r1 + r2;
        int active = 1;
        int i = 0;
        while (active) {
            if (i > 3) break;
            VEC3 diff = a->pos - b->pos;
            if (fn_801ED04C(&diff) < sum) {
                fn_801ED008(&diff, &diff);
                a->pos = b->pos + diff * (r1 + r2);
                VEC3 move;
                VEC3Sub(&move, &a->pos, &a->prev);
                if (length < fn_801ED04C(&move)) {
                    fn_801ED008(&move, &move);
                    a->pos = a->prev + move * length;
                } else {
                    active = 0;
                }
                result = 1;
            } else {
                active = 0;
            }
            ++i;
        }
    }
    return result;
}
}