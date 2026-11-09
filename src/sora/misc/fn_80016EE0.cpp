#include <gf/gf_application.h>
#include <revolution/GX/GXGeometry.h>
#pragma force_active on
extern "C" {
void fn_80016F8C(gfApplication*);
void fn_801F47D8(int, int);
void fn_801F4880(int);
void fn_801F5484(float, float, float, float, float, float);
void fn_801F5500(int, int, int, int);
void fn_801F55EC(unsigned int);
}
extern float lbl_805A13C8;
extern float lbl_805A13DC;
void gfApplication::mainLoop() {
    fn_801F47D8(*(int*)(unk0 + 0x7c), *(int*)(unk0 + 0x80));
    fn_801F5500(0, 0, *(u16*)(unk0 + 0x8c), *(u16*)(unk0 + 0x8e));
    fn_801F5484(lbl_805A13C8, lbl_805A13C8, (float)*(u16*)(unk0 + 0x8c), (float)*(u16*)(unk0 + 0x8e), lbl_805A13C8, lbl_805A13DC);
    fn_801F4880(0);
    fn_801F55EC(0);
    GXSetCullMode(GX_CULL_NONE);
    fn_80016F8C(this);
}