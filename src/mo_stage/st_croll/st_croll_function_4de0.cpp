#pragma force_active on
extern "C" {

void fn_801F0248(void);
void fn_801F3194(void);
void GXSetCullMode(int);
void GXSetZMode(int, int, int);
void GXSetZCompLoc(int);
void GXSetBlendMode(int, int, int, int);
void GXSetAlphaCompare(int, int, int, int, int);
void fn_801F471C(int);
void GXSetFog(int, unsigned char*, float, float, float, float);
void fn_801EFB10(void);
void fn_801EFB44(int, int, int, int, int);
void fn_801EF280(int, int);
void GXSetNumTexGens(int);
void GXSetTexCoordGen2(int, int, int, int, int, int);
void GXSetNumTevStages(int);
void GXSetTevOrder(int, int, int, int);
void GXSetTevOp(int, int);
void GXSetNumIndStages(int);
void fn_801F3AFC(int);
void GXSetNumChans(int);
void GXSetChanCtrl(int, int, int, int, int, int, int);
void fn_801F256C(int, int*);
void fn_801F2494(int, int*);

extern const float lbl_90_rodata_0;
extern const float lbl_90_rodata_10;
extern const float lbl_90_rodata_F4;

void fn_90_4DE0(void) {
    unsigned char color[4];
    int fogColor;
    int val1;
    int val2;

    fn_801F0248();
    fn_801F3194();
    GXSetCullMode(2);
    GXSetZMode(1, 3, 1);
    GXSetZCompLoc(0);
    GXSetBlendMode(1, 4, 5, 0);
    GXSetAlphaCompare(4, 0, 0, 7, 0);
    fn_801F471C(1);

    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    color[3] = 0;

    fogColor = *(int*)color;
    GXSetFog(0, (unsigned char*)&fogColor, lbl_90_rodata_0, lbl_90_rodata_F4, lbl_90_rodata_10, lbl_90_rodata_F4);
    fn_801EFB10();
    fn_801EFB44(0, 9, 1, 3, 0);
    fn_801EF280(9, 1);
    fn_801EFB44(0, 0xB, 1, 5, 0);
    fn_801EF280(0xB, 1);
    fn_801EFB44(0, 0xD, 1, 2, 0xE);
    fn_801EF280(0xD, 1);
    GXSetNumTexGens(1);
    GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevOp(0, 0);
    GXSetNumIndStages(0);
    fn_801F3AFC(0);
    GXSetNumChans(1);
    GXSetChanCtrl(4, 0, 0, 1, 0, 0, 2);
    GXSetChanCtrl(5, 0, 0, 1, 0, 0, 2);

    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    color[3] = 0xFF;

    val1 = *(int*)color;
    fn_801F256C(4, &val1);

    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    color[3] = 0xFF;

    val2 = *(int*)color;
    fn_801F2494(4, &val2);
}

}
