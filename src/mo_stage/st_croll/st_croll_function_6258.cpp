#pragma force_active on
extern "C" {
extern signed char lbl_90_bss_24;
extern unsigned char lbl_90_bss_28;
extern unsigned char lbl_90_bss_8[];
extern const float lbl_90_rodata_0;

void* fn_90_645C(void*, int);
void __register_global_object(void*, void*, void*);
void GXSetFog(int, unsigned char*, float, float, float, float);
void fn_801F3F5C(int, int, int, int, int);
void fn_801F4010(int, int, int);
void GXSetNumChans(int);
void GXSetChanCtrl(int, int, int, int, int, int, int);
void GXSetNumTexGens(int);
void GXSetTexCoordGen2(int, int, int, int, int, int);
void GXSetNumIndStages(int);
void GXSetBlendMode(int, int, int, int);
void GXSetNumTevStages(int);
void fn_801F3AFC(int);
void fn_801F3F20(int, int, int);
void GXSetTevOrder(int, int, int, int);
void GXSetTevOp(int, int);
void fn_801EFB44(int, int, int, int, int);
void fn_801EFB10();
void fn_801EF280(int, int);

void fn_90_6258() {
    if (lbl_90_bss_24 == 0) {
        *(int*)&lbl_90_bss_28 = 0;
        __register_global_object(&lbl_90_bss_28, (void*)fn_90_645C, lbl_90_bss_8);
        lbl_90_bss_24 = 1;
    }

    unsigned char color[4];
    unsigned char* p = &lbl_90_bss_28;
    color[0] = *p++;
    color[1] = p[0];
    color[2] = p[1];
    color[3] = p[2];

    float value = lbl_90_rodata_0;
    GXSetFog(0, color, value, value, value, value);
    fn_801F3F5C(0, 0, 1, 2, 3);
    fn_801F4010(0, 17, 0);
    GXSetNumChans(1);
    GXSetChanCtrl(4, 0, 0, 1, 0, 0, 2);
    GXSetChanCtrl(5, 0, 0, 0, 0, 0, 2);
    GXSetNumTexGens(1);
    GXSetTexCoordGen2(0, 1, 4, 60, 0, 125);
    GXSetNumIndStages(0);
    GXSetBlendMode(1, 4, 5, 15);
    GXSetNumTevStages(1);
    fn_801F3AFC(0);
    fn_801F3F20(0, 0, 0);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevOp(0, 0);
    fn_801EFB44(0, 9, 1, 4, 0);
    fn_801EFB44(0, 11, 1, 5, 0);
    fn_801EFB44(0, 13, 1, 2, 15);
    fn_801EFB10();
    fn_801EF280(9, 1);
    fn_801EF280(11, 1);
    fn_801EF280(13, 1);
}
}
