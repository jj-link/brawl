#include <revolution/GX/GXHardware.h>
#pragma force_active on

extern "C" {
void fn_801F08D8(unsigned short);
void fn_801F471C(int);
void fn_801F0530(void);
void gfDrawSetupCoord2D__Fv(void);
void gfDrawSetVtxPosColorPrimEnvironment__Fv(void);
void GXSetZMode(int, int, int);
void GXSetBlendMode(int, int, int, int);
void GXBegin(int, int, int);
extern const float lbl_805A14CC;
extern float lbl_805A14D0;
}

struct Obj {
    char pad0[0x2C];
    u32 color;
    char pad1[0x34 - 0x30];
    u16 x;
    u16 y;
    char pad2[0x74 - 0x38];
    u8 flags;
};

extern "C" void fn_8002402C(Obj* arg0) {
    if (((arg0->flags >> 7) & 1) || ((arg0->flags >> 6) & 1)) {
        fn_801F08D8(0xFFF0);
        gfDrawSetupCoord2D__Fv();
        gfDrawSetVtxPosColorPrimEnvironment__Fv();
        if ((arg0->flags >> 7) & 1) {
            fn_801F471C(1);
        } else {
            fn_801F471C(0);
        }
        if ((arg0->flags >> 6) & 1) {
            GXSetZMode(0, 7, 1);
        } else {
            GXSetZMode(0, 7, 0);
        }
        GXSetBlendMode(0, 0, 0, 0);
        f32 x = (f32)arg0->x;
        f32 y = (f32)arg0->y;
        f32 z = lbl_805A14CC;
        u32 color = arg0->color;
        GXBegin(0x98, 1, 4);
        WGPIPE.f = lbl_805A14D0;
        WGPIPE.f = lbl_805A14D0;
        WGPIPE.f = z;
        WGPIPE.ui = color;
        WGPIPE.f = x;
        WGPIPE.f = lbl_805A14D0;
        WGPIPE.f = z;
        WGPIPE.ui = color;
        WGPIPE.f = lbl_805A14D0;
        WGPIPE.f = y;
        WGPIPE.f = z;
        WGPIPE.ui = color;
        WGPIPE.f = x;
        WGPIPE.f = y;
        WGPIPE.f = z;
        WGPIPE.ui = color;
        fn_801F0530();
    }
}
