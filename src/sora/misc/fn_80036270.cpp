#include <types.h>
#include <revolution/MTX/mtx.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on

typedef struct {
    u8 r, g, b, a;
} Color4;

extern "C" {

void GXSetNumChans(int);
void GXSetChanCtrl(int, int, int, int, int, int, int);
void GXSetNumTexGens(int);
void GXSetTexCoordGen2(int, int, int, int, int, int);
void GXSetNumTevStages(int);
void GXSetTevOrder(int, int, int, int);
void GXSetBlendMode(int, int, int, int);
void GXSetZMode(int, int, int);
void GXBegin(int, int, int);

void fn_801EFB10(void);
void fn_801EFB44(int, int, int, int, int);
void fn_801EF280(int, int);
void fn_801F3D60(int, const void*);
void fn_801F3C30(int, int, int, int, int);
void fn_801F3CB0(int, int, int, int, int, int);
void fn_801F3C70(int, int, int, int, int);
void fn_801F3D08(int, int, int, int, int, int);
void fn_801F51DC(const void*, int);
void fn_801F52E4(int);
void fn_8025C058(s32, void*, int);
void fn_801F2FB0(void*, int);
void* fn_80023AC8(void);
void fn_801ECF4C(void*, f32, f32, f32, f32, f32, f32);
void fn_801F50EC(void*, int);
void setIdentity__6MatrixFv(void*);

extern void* lbl_805A0098;
extern u8 lbl_805A1670;
extern u8 lbl_805A1671;
extern u8 lbl_805A1672;
extern f32 lbl_805A1674;
extern f32 lbl_805A1678;
extern f32 lbl_805A167C;
extern f32 lbl_805A1680;
extern f32 lbl_805A1684;
extern f32 lbl_805A1688;

void fn_80036270(s32 arg0, s8 arg1, s32 arg2) {
    Mtx sp70;
    Mtx44 sp30;
    f32 sp10[8];
    s32 spC;
    Color4 c;

    fn_801EFB10();
    fn_801EFB44(5, 9, 0, 4, 0);
    fn_801EFB44(5, 0xD, 1, 3, 0);
    fn_801EF280(9, 1);
    fn_801EF280(0xD, 1);
    GXSetNumChans(1);
    GXSetChanCtrl(4, 0, 1, 1, 0, 0, 2);
    GXSetNumTexGens(1);
    GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
    GXSetNumTevStages(1);
    c.r = lbl_805A1670;
    c.g = lbl_805A1671;
    c.b = lbl_805A1672;
    c.a = arg1;
    spC = *(s32*)&c;
    fn_801F3D60(1, &spC);
    GXSetTevOrder(0, 0, 0, 0xFF);
    fn_801F3C30(0, 0xF, 0xF, 0xF, 8);
    fn_801F3CB0(0, 0, 0, 0, 1, 0);
    fn_801F3C70(0, 7, 1, 4, 7);
    fn_801F3D08(0, 0, 0, 0, 1, 0);
    GXSetBlendMode(1, 4, 5, 0);
    GXSetZMode(0, 3, 0);
    setIdentity__6MatrixFv(sp70);
    fn_801F51DC(sp70, 3);
    fn_801F52E4(3);
    fn_8025C058(arg0, sp10, 0);
    fn_801F2FB0(sp10, 0);

    u8* p = (u8*)fn_80023AC8();
    f32 f31 = (f32)(s32)*(u16*)(p + 0x34);
    f32 f30 = (f32)(s32)*(u16*)(p + 0x36);
    fn_801ECF4C(sp30, f30 * lbl_805A1674, -f30 * lbl_805A1674, -f31 * lbl_805A1674, f31 * lbl_805A1674, lbl_805A1678, lbl_805A167C);
    fn_801F50EC(sp30, 1);

    f32 b = lbl_805A1680;
    f32 var_f4 = lbl_805A1684;
    f32 k = lbl_805A1684;
    var_f4 *= *(f32*)((u8*)lbl_805A0098 + 0x44);
    if (arg2 != 0) {
        var_f4 *= lbl_805A1688;
    }
    f32 temp_f1 = -f31 * lbl_805A1674;
    f32 temp_f30_2 = temp_f1 + b;
    f32 temp_f31_2 = temp_f30_2 + var_f4;
    f32 temp_f29 = (f30 * lbl_805A1674) - b;
    f32 temp_f28 = temp_f29 - k;

    GXBegin(0x80, 5, 4);
    WGPIPE.f = temp_f30_2;
    WGPIPE.f = temp_f28;
    WGPIPE.s = 0;
    WGPIPE.s = 1;
    WGPIPE.f = temp_f30_2;
    WGPIPE.f = temp_f29;
    WGPIPE.s = 0;
    WGPIPE.s = 0;
    WGPIPE.f = temp_f31_2;
    WGPIPE.f = temp_f29;
    WGPIPE.s = 1;
    WGPIPE.s = 0;
    WGPIPE.f = temp_f31_2;
    WGPIPE.f = temp_f28;
    WGPIPE.s = 1;
    WGPIPE.s = 1;
}

}
