#include <types.h>
#include <mt/mt_matrix.h>
#include <gf/gf_draw.h>
#include <revolution/GX.h>
#pragma force_active on
extern "C" {
extern f32 lbl_805A15A0, lbl_805A15A4, lbl_805A15A8, lbl_805A15AC, lbl_805A15B0;
u8* fn_80023AC8();
void fn_801ECF4C(void*, f32, f32, f32, f32, f32, f32);
void fn_801F5484(f32, f32, f32, f32, f32, f32);
void fn_801F50EC(void*, int);
void fn_801F5500(int, int, u16, u16);
void fn_801F55B0(int, int);
void fn_801F51DC(const void*, unsigned int);
void fn_801F52E4(int);
void fn_801EFB10();
void fn_801EF280(int, int);
void fn_801EFB44(int, int, int, int, int);
void fn_801F55EC(int);
void fn_801F256C(int, GXColor*);
void fn_801F0248();
void fn_801F1394(int);
void fn_801F3194();
void fn_801F4010(int, int, int);
void fn_801F3F20(int, int, int);
void fn_801F3F5C(int, int, int, int, int);
void fn_801F45A8(int, int, int);
void fn_801F471C(int);
void fn_801F4748(int);
}
inline void initColor(GXColor* c) {
    c->r = 255; c->g = 255; c->b = 255; c->a = 255;
}
extern "C" void fn_8002F6F4() {
    struct { GXColor color; f32 projection[4][4]; Matrix matrix; } locals;
    initColor(&locals.color);
    u16 width = *(u16*)(fn_80023AC8() + 0x34);
    u16 height = *(u16*)(fn_80023AC8() + 0x36);
    u32 halfWidth = width >> 1;
    s32 left = -halfWidth;
    u32 halfHeight = height >> 1;

    fn_801ECF4C(locals.projection, (f32)halfHeight, (f32)-(s32)halfHeight,
                (f32)left, (f32)halfWidth, lbl_805A15A0, lbl_805A15A4);
    fn_801F5484(lbl_805A15A8, lbl_805A15A8, (f32)width, (f32)height,
                lbl_805A15A8, lbl_805A15AC);
    fn_801F50EC(locals.projection, 1);
    fn_801F5500(0, 0, width, height);
    fn_801F55B0(0, 0);
    locals.matrix.m[0][3] = (f32)left;
    locals.matrix.m[1][1] = lbl_805A15B0;
    locals.matrix.m[1][3] = (f32)(u16)halfHeight;
    fn_801F51DC(&locals.matrix, 0);
    fn_801F52E4(0);
    GXSetZMode(1, GX_ALWAYS, 0);
    gfDrawSetVtxPosColorTexPrimEnvironment();
    fn_801EFB10();
    fn_801EF280(9, 1);
    fn_801EF280(13, 1);
    fn_801EFB44(1, 9, 1, 4, 0);
    fn_801EFB44(1, 13, 1, 4, 0);
    fn_801F55EC(1);
    GXSetCullMode(GX_CULL_NONE);
    GXSetChanCtrl(GX_COLOR0A0, 0, GX_SRC_REG, GX_SRC_REG,
                  GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXColor copy;
    copy.r = locals.color.r;
    copy.g = locals.color.g;
    copy.b = locals.color.b;
    copy.a = locals.color.a;
    fn_801F256C(4, &copy);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
    GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_AND, GX_ALWAYS, 0);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    fn_801F0248();
    fn_801F1394(0);
    fn_801F3194();
    fn_801F4010(0, 17, 0);
    fn_801F3F20(0, 0, 0);
    fn_801F3F5C(0, 0, 1, 2, 3);
    fn_801F45A8(0, 0, 0);
    fn_801F471C(1);
    fn_801F4748(1);
    GXSetZCompLoc(1);
}