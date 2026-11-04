#include <revolution/GX/GXGeometry.h>
#include <revolution/GX/GXVert.h>

#pragma force_active on

extern "C" {

void fn_801F28F0(void *, u32, u16, u16, u32, u32, u32, u8);
void fn_801F2B44(void *, s32, s32, s32, s32, s32, f32, f32, f32);
void fn_801F2FB0(void *, s32);
extern f32 lbl_805A1B2C;

void fn_8007BAC8(int a0, int a1, int a2, s16 a3, s16 a4, int a5, int a6, s16 a7, s16 a8) {
    u32 sp48[8];
    u32 sp28[8];
    u32 sp8[8];
    s32 h5;
    s32 h6;

    fn_801F28F0((void *)sp48, (u32)a0, (u16)(a5 & 0xFFFF), (u16)(a6 & 0xFFFF), 1, 0, 0, (u8)0);
    fn_801F2B44((void *)sp48, 1, 1, 0, 0, 0, lbl_805A1B2C, lbl_805A1B2C, lbl_805A1B2C);
    fn_801F2FB0((void *)sp48, 0);

    h5 = a5 >> 1;
    h6 = a6 >> 1;

    fn_801F28F0((void *)sp28, (u32)a1, (u16)((a5 >> 1) & 0xFFFF), (u16)((a6 >> 1) & 0xFFFF), 1, 0, 0, (u8)0);
    fn_801F2B44((void *)sp28, 1, 1, 0, 0, 0, lbl_805A1B2C, lbl_805A1B2C, lbl_805A1B2C);
    fn_801F2FB0((void *)sp28, 1);

    fn_801F28F0((void *)sp8, (u32)a2, (u16)h5, (u16)h6, 1, 0, 0, (u8)0);
    fn_801F2B44((void *)sp8, 1, 1, 0, 0, 0, lbl_805A1B2C, lbl_805A1B2C, lbl_805A1B2C);
    fn_801F2FB0((void *)sp8, 2);

    GXBegin(GX_QUADS, GX_VTXFMT7, 4);

    WGPIPE.us = a3;
    WGPIPE.us = a4;
    WGPIPE.us = 0;
    WGPIPE.us = 0;
    WGPIPE.us = 0;
    WGPIPE.us = a3 + a7;
    WGPIPE.us = a4;
    WGPIPE.us = 0;
    WGPIPE.us = 1;
    WGPIPE.us = 0;
    WGPIPE.us = a3 + a7;
    WGPIPE.us = a4 + a8;
    WGPIPE.us = 0;
    WGPIPE.us = 1;
    WGPIPE.us = 1;
    WGPIPE.us = a3;
    WGPIPE.us = a4 + a8;
    WGPIPE.us = 0;
    WGPIPE.us = 0;
    WGPIPE.us = 1;
}

}
