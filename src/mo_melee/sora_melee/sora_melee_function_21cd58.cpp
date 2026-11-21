#include <types.h>
#pragma force_active on
struct Obj { s32 f0; s32 f4; s8 f8; char pad9[3]; s32 fc; f32 f10; };
extern "C" void fn_27_21CD58(Obj* p) {
    p->f0 = 0;
    p->f4 = 0;
    p->f8 = 100;
    f32 value = p->f8 - 20;
    value *= 0.5f;
    if (value < 0.0f)
        value = 0.0f;
    else if (value > 30.0f)
        value = 30.0f;
    p->f10 = value;
    p->fc = 0;
}