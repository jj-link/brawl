#include <types.h>
#include <sr/sr_common.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_types.h>
#pragma force_active on

extern "C" {
void fn_80010D5C(void*, void*, unsigned int);
void fn_8001133C(void*, void*, void*);
void fn_80011528(void*, void*, float);
extern float lbl_27_rodata_38F0;
extern const float lbl_27_rodata_38F4;
extern char lbl_804207A0[];
extern char lbl_80420768[];
}

struct AreaFlags {
    unsigned int reserved : 24;
    unsigned int kind : 8;
};

struct AreaData {
    s32 kind, a, b, c;
    u16 d, e;
    s32 f;
    f32 x, y, w, h;
};

extern "C" void fn_27_234DDC(void* self, AreaData src, Vec2f vec) {
    char* s = (char*)self;
    char* p = (char*)&src;
    char* v = (char*)&vec;

    f32 f1c;
    f32 f18;
    s32 f14;
    u16 f12;
    u16 f10;
    s32 fc;
    s32 f8;
    s32 f4;
    s32 f0;

    f0 = *(s32*)(p + 0x00);
    f18 = *(f32*)(p + 0x18);
    f1c = *(f32*)(p + 0x1C);
    *(f32*)(s + 0x2C) = f18;
    f4 = *(s32*)(p + 0x04);
    *(f32*)(s + 0x30) = f1c;
    f8 = *(s32*)(p + 0x08);
    fc = *(s32*)(p + 0x0C);
    f10 = *(u16*)(p + 0x10);
    f12 = *(u16*)(p + 0x12);
    f14 = *(s32*)(p + 0x14);
    f32 f24;
    f32 f20 = *(f32*)(p + 0x20);
    f24 = *(f32*)(p + 0x24);
    *(s32*)(s + 0x14) = f0;
    *(s32*)(s + 0x18) = f4;
    *(s32*)(s + 0x1C) = f8;
    *(s32*)(s + 0x20) = fc;
    *(u16*)(s + 0x24) = f10;
    *(u16*)(s + 0x26) = f12;
    *(s32*)(s + 0x28) = f14;
    *(f32*)(s + 0x34) = f20;
    *(f32*)(s + 0x38) = f24;
    *(nw4r::math::VEC2*)(s + 0x2C) += *(nw4r::math::VEC2*)v;

    f32 pa[2];
    f32 pd[2];
    f32 pc[2];
    f32 pe[2];
    f32 pf[2];
    f32 pb[2];

    char* o;
    if (f0 == 0) {
        o = (char*)operator new(0x68, Heaps::StageInstance);
        if (o) {
            pa[0] = lbl_27_rodata_38F0;
            pa[1] = lbl_27_rodata_38F0;
            fn_80010D5C(o, pa, 1);
            *(void**)(o + 0x44) = lbl_804207A0;
            f32 c = lbl_27_rodata_38F4;
            *(s32*)(o + 0x18) = 0;
            pb[0] = c;
            pb[1] = c;
            fn_8001133C(o, pa, pb);
        }
        f32 cx, cy;
        cy = *(f32*)(s + 0x38);
        cx = *(f32*)(s + 0x34);
        pc[0] = cx;
        pc[1] = cy;
        f32 dx, dy;
        dy = *(f32*)(s + 0x30);
        dx = *(f32*)(s + 0x2C);
        pd[0] = dx;
        pd[1] = dy;
        fn_8001133C(o, pd, pc);
        *(void**)(s + 0x10) = o;
    } else {
        o = (char*)operator new(0x54, Heaps::StageInstance);
        if (o) {
            pe[0] = lbl_27_rodata_38F0;
            pe[1] = lbl_27_rodata_38F0;
            fn_80010D5C(o, pe, 1);
            void* table = lbl_80420768;
            f32 c = lbl_27_rodata_38F4;
            *(void**)(o + 0x44) = table;
            *(s32*)(o + 0x18) = 1;
            fn_80011528(o, pe, c);
        }
        f32 px, py;
        py = *(f32*)(p + 0x1C);
        px = *(f32*)(p + 0x18);
        pf[1] = py;
        pf[0] = px;
        fn_80011528(o, pf, *(f32*)(s + 0x34));
        *(void**)(s + 0x10) = o;
    }

    char*& t = *(char**)(s + 0x10);
    ((AreaFlags*)(t + 0x1C))->kind = 2;
    *(u8*)(t + 0x1D) = (u8)*(s32*)(s + 0x18);
    *(s32*)(t + 0x08) = *(s32*)(s + 0x1C);
    *(s32*)(t + 0x0C) = *(s32*)(s + 0x20);
}
