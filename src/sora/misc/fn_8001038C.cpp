#include <types.h>
#include <revolution/MTX/mtx.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on
extern "C" {
void fn_801A7550(void*, void*);
void fn_801A7558(void*);
void fn_801A7A5C(void*, float, float, float, float, float, float);
void fn_801A7ABC(void*, float, float, float, float);
void fn_801A7B58(void*, float, float);
void fn_801A8048(void*);
void fn_801A80CC(void*);
void fn_801A8194(void*);
void fn_801A81B8(void*);
void fn_8001025C(s32*);
void fn_801EC158(void*);
void fn_801F51DC(void*, unsigned int);
void fn_801EFB10();
void fn_801EF280(int, int);
void fn_801EFB44(int, int, int, int, int);
void fn_801F52E4(int);
void fn_801F54D0(float, float);
void GXSetZMode(int, int, int);
void GXBegin(int, int, int);
extern f32 lbl_805A1324, lbl_805A1330, lbl_805A1360, lbl_805A1384, lbl_805A1388;
}
extern "C" void fn_8001038C(s32 arg0, s32 arg1) {
    Mtx sp10;
    u8 sp40[0x110];
    s32 spC;
    s32 sp8;
    f32 temp_f31;
    f32 temp_f30;
    fn_801A7550(&spC, &sp40);
    fn_801A7558(&spC);
    fn_801A7A5C(&spC, lbl_805A1324, (f32)arg1, lbl_805A1324, (f32)arg0, lbl_805A1330, lbl_805A1384);
    fn_801A7ABC(&spC, lbl_805A1324, lbl_805A1324, (f32)arg0, (f32)arg1);
    fn_801A7B58(&spC, lbl_805A1324, lbl_805A1388);
    fn_801A8048(&spC);
    fn_801A80CC(&spC);
    fn_801A8194(&spC);
    fn_801A81B8(&spC);
    sp8 = 0;
    fn_8001025C(&sp8);
    GXSetZMode(0, 7, 0);
    fn_801EC158(&sp10);
    fn_801F51DC(&sp10, 0);
    fn_801EFB10();
    fn_801EF280(9, 1);
    fn_801EFB44(7, 9, 1, 4, 0);
    temp_f31 = (f32)arg1;
    temp_f30 = (f32)arg0;
    fn_801F52E4(0);
    fn_801F54D0(lbl_805A1330, lbl_805A1324);
    GXBegin(0x98, 7, 4);
    WGPIPE.f = lbl_805A1324;
    WGPIPE.f = lbl_805A1324;
    WGPIPE.f = lbl_805A1360;
    WGPIPE.f = temp_f30;
    WGPIPE.f = lbl_805A1324;
    WGPIPE.f = lbl_805A1360;
    WGPIPE.f = lbl_805A1324;
    WGPIPE.f = temp_f31;
    WGPIPE.f = lbl_805A1360;
    WGPIPE.f = temp_f30;
    WGPIPE.f = temp_f31;
    WGPIPE.f = lbl_805A1360;
}