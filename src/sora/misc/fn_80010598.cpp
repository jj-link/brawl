#include <types.h>
#include <mt/mt_matrix.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on
extern "C" {
void fn_801A7550(void*, void*);
void fn_801A7558(void*);
void fn_801A7A5C(void*, float, float, float, float, float, float);
void fn_801A7ABC(void*, float, float, float, float);
void fn_801A8048(void*);
void fn_801A80CC(void*);
void fn_801A8194(void*);
void fn_801A81B8(void*);
void fn_8001025C(s32*);
void GXSetZCompLoc(int);
void GXSetZMode(int, int, int);
void fn_801F471C(int);
void fn_801F55EC(int);
void fn_801F51DC(void*, unsigned int);
void fn_801EFB10();
void fn_801EF280(int, int);
void fn_801EFB44(int, int, int, int, int);
void fn_801F52E4(int);
void GXBegin(int, int, int);
extern f32 lbl_805A1324, lbl_805A1330, lbl_805A138C;
}
extern "C" void fn_80010598(s32 arg0, s32 arg1) {
    Matrix sp10(true);
    u8 sp40[0x110];
    s32 spC;
    s32 sp8;
    f32 temp_f31;
    f32 temp_f30;
    fn_801A7550(&spC, &sp40);
    fn_801A7558(&spC);
    fn_801A7A5C(&spC, lbl_805A1324, (f32)arg1, lbl_805A1324, (f32)arg0, lbl_805A1324, lbl_805A1330);
    fn_801A7ABC(&spC, lbl_805A1324, lbl_805A1324, (f32)arg0, (f32)arg1);
    fn_801A8048(&spC);
    fn_801A80CC(&spC);
    fn_801A8194(&spC);
    fn_801A81B8(&spC);
    sp8 = 0;
    fn_8001025C(&sp8);
    GXSetZCompLoc(1);
    GXSetZMode(1, 7, 1);
    fn_801F471C(0);
    fn_801F55EC(1);
    sp10.setIdentity();
    fn_801F51DC(&sp10, 0);
    fn_801EFB10();
    fn_801EF280(9, 1);
    fn_801EFB44(7, 9, 1, 4, 0);
    temp_f31 = (f32)arg1;
    temp_f30 = (f32)arg0;
    fn_801F52E4(0);
    GXBegin(0x98, 7, 4);
    WGPIPE.f = lbl_805A1324;
    WGPIPE.f = lbl_805A1324;
    WGPIPE.f = lbl_805A138C;
    WGPIPE.f = temp_f30;
    WGPIPE.f = lbl_805A1324;
    WGPIPE.f = lbl_805A138C;
    WGPIPE.f = lbl_805A1324;
    WGPIPE.f = temp_f31;
    WGPIPE.f = lbl_805A138C;
    WGPIPE.f = temp_f30;
    WGPIPE.f = temp_f31;
    WGPIPE.f = lbl_805A138C;
    fn_801F471C(1);
}