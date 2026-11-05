#include <types.h>
#include <revolution/MTX/mtx.h>
#include <revolution/GX/GXHardware.h>

#pragma force_active on

extern "C" {

void fn_801A7550(void* self, void* value);
void fn_801A7558(void* self);
void fn_801A7A5C(void* self, float f1, float f2, float f3, float f4, float f5, float f6);
void fn_801A7ABC(void* self, float f1, float f2, float f3, float f4);
void fn_801A7B58(void* self, float f1, float f2);
void fn_801A8048(void* self);
void fn_801A80CC(void* self);
void fn_801A8194(void* self);
void fn_801A81B8(void* self);
void fn_801F54D0(float x, float y);
void fn_8001025C(s32* p);
void fn_801EC158(void* p);
void fn_801F51DC(void* p, unsigned int v);
void fn_801EFB10(void);
void fn_801EF280(int, int);
void fn_801EFB44(int, int, int, int, int);
void fn_801F52E4(int);
void GXSetZMode(int, int, int);
void GXSetLineWidth(int, int);
void GXBegin(int, int, int);

extern f32 lbl_805A1324;
extern f32 lbl_805A1330;
extern f32 lbl_805A135C;
extern f32 lbl_805A1380;

}

extern "C" void fn_800107A8(s32 arg0, s32 arg1) {
    Mtx sp10;
    u8 sp40[0x110];
    s32 spC;
    s32 sp8;
    f32 temp_f31;
    f32 temp_f30;

    fn_801A7550(&spC, &sp40);
    fn_801A7558(&spC);
    fn_801A7A5C(&spC, lbl_805A1324, (f32)arg1, lbl_805A1324, (f32)arg0, lbl_805A1324, lbl_805A1330);
    fn_801A7ABC(&spC, lbl_805A1324, lbl_805A1324, (f32)arg0, (f32)arg1);
    fn_801A7B58(&spC, lbl_805A1324, lbl_805A1380);
    fn_801A8048(&spC);
    fn_801A80CC(&spC);
    fn_801A8194(&spC);
    fn_801A81B8(&spC);
    fn_801F54D0(lbl_805A1330, lbl_805A1324);
    sp8 = 0;
    fn_8001025C(&sp8);
    GXSetZMode(1, 7, 1);
    fn_801EC158(&sp10);
    fn_801F51DC(&sp10, 0);
    fn_801EFB10();
    fn_801EF280(9, 1);
    fn_801EFB44(7, 9, 1, 4, 0);
    GXSetLineWidth(0x18, 0);
    temp_f31 = (f32)arg1;
    temp_f30 = (f32)arg0;
    fn_801F52E4(0);
    GXBegin(0xB0, 7, 5);
    WGPIPE.f = lbl_805A135C;
    WGPIPE.f = lbl_805A135C;
    WGPIPE.f = lbl_805A1324;
    WGPIPE.f = temp_f30;
    WGPIPE.f = lbl_805A135C;
    WGPIPE.f = lbl_805A1324;
    WGPIPE.f = temp_f30;
    WGPIPE.f = temp_f31;
    WGPIPE.f = lbl_805A1324;
    WGPIPE.f = lbl_805A135C;
    WGPIPE.f = temp_f31;
    WGPIPE.f = lbl_805A1324;
    WGPIPE.f = lbl_805A135C;
    WGPIPE.f = lbl_805A135C;
    WGPIPE.f = lbl_805A1324;
}
