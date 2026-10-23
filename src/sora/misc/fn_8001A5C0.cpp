#pragma force_active on
extern "C" {

void fn_801F52E4(int);
void fn_801F55EC(int);
void fn_801F3AFC(int);
void fn_801F256C(int, int*);
void fn_801F2494(int, int*);
void fn_801EFB10(void);
void fn_801EF280(int, int);
void fn_801EFB44(int, int, int, int, int);
void fn_801F3F20(int, int, int);
void fn_801F3F5C(int, int, int, int, int);
void GXSetNumTexGens(int);
void GXSetTevOrder(int, int, int, int);
void GXSetTevOp(int, int);
void GXSetNumTevStages(int);
void GXSetNumIndStages(int);
void GXSetNumChans(int);
void GXSetChanCtrl(int, int, int, int, int, int, int);
void GXSetZMode(int, int, int);
void GXSetBlendMode(int, int, int, int);
void GXSetZCompLoc(int);
void GXSetAlphaCompare(int, int, int, int, int);
void GXSetFog(int, unsigned char*, float, float, float, float);

extern float lbl_805A1460;
extern float lbl_805A1464;
extern float lbl_805A1468;

void gfDrawSetVtxPosColorPrimEnvironment__Fv() {
    unsigned char color[4];
    int val1;
    int val2;
    int fogColor;
    
    fn_801F52E4(0);
    fn_801F55EC(0);
    
    color[0] = 0xFF;
    color[1] = 0xFF;
    color[2] = 0xFF;
    color[3] = 0xFF;
    
    GXSetNumTexGens(0);
    GXSetTevOrder(0, 0xFF, 0xFF, 4);
    GXSetTevOp(0, 4);
    GXSetNumTevStages(1);
    fn_801F3AFC(0);
    GXSetNumIndStages(0);
    GXSetNumChans(1);
    GXSetChanCtrl(4, 0, 0, 1, 0, 0, 2);
    GXSetChanCtrl(5, 0, 0, 1, 0, 0, 2);
    
    val1 = *(int*)color;
    fn_801F256C(4, &val1);
    
    val2 = *(int*)color;
    fn_801F2494(4, &val2);
    
    GXSetZMode(1, 7, 0);
    GXSetBlendMode(1, 4, 5, 0);
    GXSetZMode(0, 7, 0);
    GXSetZCompLoc(0);
    GXSetAlphaCompare(4, 0, 0, 4, 0);
    fn_801EFB10();
    fn_801EF280(9, 1);
    fn_801EF280(0xB, 1);
    fn_801EFB44(1, 9, 1, 4, 0);
    fn_801EFB44(1, 0xB, 1, 5, 0);
    
    color[2] = 0;
    color[1] = 0;
    color[0] = 0;
    
    fogColor = *(int*)color;
    GXSetFog(0, (unsigned char*)&fogColor, lbl_805A1460, lbl_805A1464, lbl_805A1468, lbl_805A1464);
    
    fn_801F3F20(0, 0, 0);
    fn_801F3F5C(0, 0, 1, 2, 3);
}

}
