#include <types.h>
#pragma force_active on

typedef struct Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u8 unkC[0x20 - 0x0C];
    f32 unk20;
    f32 unk24;
    u8 unk28[0x5C - 0x28];
    u8 unk5C;
    u8 unk5D[0x60 - 0x5D];
    u32 unk60;
    u32 unk64;
    u32 unk68;
} Obj;

typedef struct Obj2 {
    u8 pad[0x24];
    f32 unk24;
} Obj2;

typedef struct Src {
    Obj *unk0;
    f32 unk4;
    f32 unk8;
    u32 unkC;
} Src;

typedef struct Dst {
    u8 unk0[0x8];
    f32 unk8;
    f32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
} Dst;

void fn_8027A694(Dst *arg0, Src *arg1, s32 arg2)
{
    Obj *obj;
    u32 v;
    Obj *o7;
    u32 f60;
    u32 f64;
    u32 f68;
    f32 fb;
    f32 fa;

    obj = arg1->unk0;
    if (obj == 0) {
        return;
    }
    if (arg2 != 0) {
        if (obj->unk5C == 2 && arg1->unkC == 2) {
            fa = arg1->unk4;
            fb = arg1->unk8;
            arg0->unk8 = fa;
            arg0->unkC = fb;
        } else {
            f32 a = obj->unk20;
            Obj2 *p = *(Obj2 **)arg1;
            arg0->unk8 = a;
            arg0->unkC = p->unk24;
        }
    }
    o7 = arg1->unk0;
    arg0->unk10 = o7->unk4;
    v = o7->unk0;
    arg0->unk14 = v;
    arg0->unk18 = o7->unk8;
    if (o7->unk5C == 2 && arg1->unkC == 2) {
        f60 = o7->unk60;
        f64 = o7->unk64;
        f68 = o7->unk68;
        if (f60 & 0x10) {
            arg0->unk14 = v | 0x800;
        }
        if (f64 & 0x10) {
            arg0->unk10 |= 0x800;
        }
        if (f68 & 0x10) {
            arg0->unk18 |= 0x800;
        }
        if (f60 & 0x400) {
            arg0->unk14 |= 0x10;
        }
        if (f64 & 0x400) {
            arg0->unk10 |= 0x10;
        }
        if (f68 & 0x400) {
            arg0->unk18 |= 0x10;
        }
        if (f60 & 0x1000) {
            arg0->unk14 |= 0x1000;
        }
        if (f64 & 0x1000) {
            arg0->unk10 |= 0x1000;
        }
        if (f68 & 0x1000) {
            arg0->unk18 |= 0x1000;
        }
        if (f60 & 0x800) {
            arg0->unk14 |= 0x8000;
        }
        if (f64 & 0x800) {
            arg0->unk10 |= 0x8000;
        }
        if (f68 & 0x800) {
            arg0->unk18 |= 0x8000;
        }
    }
}
