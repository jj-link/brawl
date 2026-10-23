#include <types.h>
#pragma force_active on

extern void fn_80285CCC(void*);
extern void fn_80285A6C(void*, s32);
extern const f32 lbl_805A3CC8;
extern const f32 lbl_805A3CCC;

typedef struct Vec4 {
    f32 x, y, z, w;
} Vec4;

typedef struct Obj {
    u8 pad0[0x30];
    Vec4 value;
    u8 pad40[0x50];
    f32 a, b, c, d, e;
} Obj;

void fn_80281FB0(Obj* arg0, const Vec4* arg1, s32 arg2) {
    fn_80285CCC((u8*)arg0 + 0x40);
    fn_80285A6C(arg0, arg2);
    arg0->value.x = arg1->x;
    arg0->value.y = arg1->y;
    arg0->value.z = arg1->z;
    arg0->value.w = arg1->w;
    arg0->a = arg0->b = arg0->c = arg0->d = lbl_805A3CC8;
    arg0->e = lbl_805A3CCC;
}
