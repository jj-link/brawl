#pragma force_active on
extern "C" {
extern signed char lbl_805A04A8;
extern unsigned char lbl_805A04AC;
extern unsigned char lbl_805A04AD;
extern unsigned char lbl_805A04AE;
extern unsigned char lbl_805A04AF;
extern unsigned char lbl_8049ED90[16];
extern float lbl_805A2BB8;

void __register_global_object(void*, void*, void*);
void __dt__Q34nw4r2ut5ColorFv(void*, short);
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
void fn_801F3D60(int, unsigned char*, int, int, int);
void fn_801F3C30(int, int, int, int, int);
void fn_801F3C70(int, int, int, int, int);
void fn_801F3CB0(int, int, int, int, int, int);
void fn_801F3D08(int, int, int, int, int, int);
void fn_801EFB44(int, int, int, int, int);
void fn_801EFB10(void);
void fn_801EF280(int, int);
}

static inline void copyFogColor(unsigned char* dst) {
    unsigned char* p = &lbl_805A04AC;
    dst[0] = *p++;
    dst[1] = lbl_805A04AD;
    dst[2] = lbl_805A04AE;
    dst[3] = lbl_805A04AF;
}

extern "C" void fn_8015FE30(unsigned char* arg0, unsigned char* arg1) {
    unsigned char t7;
    unsigned char t6;
    unsigned char t5;
    unsigned char t4;
    unsigned char c0[4];
    unsigned char c1[4];
    unsigned char color[4];

    if (lbl_805A04A8 == 0) {
        *(int*)&lbl_805A04AC = 0;
        __register_global_object(&lbl_805A04AC, (void*)__dt__Q34nw4r2ut5ColorFv, lbl_8049ED90);
        lbl_805A04A8 = 1;
    }

    copyFogColor(color);
    GXSetFog(0, color, lbl_805A2BB8, lbl_805A2BB8, lbl_805A2BB8, lbl_805A2BB8);
    fn_801F3F5C(0, 0, 1, 2, 3);
    fn_801F4010(0, 17, 0);
    GXSetNumChans(1);
    GXSetChanCtrl(4, 0, 0, 1, 0, 0, 2);
    GXSetChanCtrl(5, 0, 0, 0, 0, 0, 2);
    GXSetNumTexGens(1);
    GXSetTexCoordGen2(0, 1, 4, 60, 0, 125);
    GXSetNumIndStages(0);
    GXSetBlendMode(1, 4, 5, 15);
    GXSetNumTevStages(2);
    fn_801F3AFC(0);
    fn_801F3AFC(1);
    fn_801F3F20(0, 0, 0);
    fn_801F3F20(1, 0, 0);
    GXSetTevOrder(0, 0, 0, 255);

    t7 = arg0[0];
    t6 = arg0[1];
    t5 = arg0[2];
    t4 = arg0[3];
    c0[0] = t7;
    c0[1] = t6;
    c0[2] = t5;
    c0[3] = t4;
    fn_801F3D60(1, c0, t5, t6, t7);

    t7 = arg1[0];
    t6 = arg1[1];
    t5 = arg1[2];
    t4 = arg1[3];
    c1[0] = t7;
    c1[1] = t6;
    c1[2] = t5;
    c1[3] = t4;
    fn_801F3D60(2, c1, t5, t6, t7);

    fn_801F3C30(0, 2, 4, 8, 15);
    fn_801F3C70(0, 1, 2, 4, 7);
    fn_801F3CB0(0, 0, 0, 0, 1, 0);
    fn_801F3D08(0, 0, 0, 0, 1, 0);
    GXSetTevOrder(1, 255, 255, 4);
    fn_801F3C30(1, 15, 0, 10, 15);
    fn_801F3C70(1, 7, 0, 5, 7);
    fn_801F3CB0(1, 0, 0, 0, 1, 0);
    fn_801F3D08(1, 0, 0, 0, 1, 0);
    fn_801EFB44(0, 9, 1, 4, 0);
    fn_801EFB44(0, 11, 1, 5, 0);
    fn_801EFB44(0, 13, 1, 2, 15);
    fn_801EFB10();
    fn_801EF280(9, 1);
    fn_801EF280(11, 1);
    fn_801EF280(13, 1);
}
