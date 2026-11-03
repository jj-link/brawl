#pragma force_active on
extern "C" {
void fn_801F51DC(void*, int);
void fn_801F52E4(int);
void GXSetBlendMode(int, int, int, int);
void fn_801F471C(int);
void GXSetChanCtrl(int, int, int, int, int, int, int);
void GXSetFog(int, unsigned char*, float, float, float, float);
void fn_801EFB10();
void fn_801EFB44(int, int, int, int, int);
void fn_801EF280(int, int);
void GXSetNumTexGens(int);
void GXSetNumChans(int);
void GXSetTevOp(int, int);
void GXSetTevOrder(int, int, int, int);
void GXSetZMode(int, int, int);
void GXSetZCompLoc(int);
void GXSetCullMode(int);
extern unsigned char lbl_805A1660, lbl_805A1661, lbl_805A1662, lbl_805A1663;
extern float lbl_805A1664, lbl_805A1668, lbl_805A1614, lbl_805A1600;
void fn_800360EC(void* unused, void* matrix) {
    unsigned char color[4];
    fn_801F51DC(matrix, 3);
    fn_801F52E4(3);
    GXSetBlendMode(0, 0, 0, 0);
    fn_801F471C(1);
    GXSetChanCtrl(4, 0, 1, 1, 1, 0, 2);
    color[0] = lbl_805A1660;
    color[1] = lbl_805A1661;
    color[2] = lbl_805A1662;
    color[3] = lbl_805A1663;
    GXSetFog(10, color, lbl_805A1664, lbl_805A1668, lbl_805A1614, lbl_805A1600);
    fn_801EFB10();
    fn_801EFB44(0, 9, 1, 4, 0);
    fn_801EF280(9, 1);
    GXSetNumTexGens(0);
    GXSetNumChans(1);
    fn_801EF280(13, 0);
    GXSetTevOp(0, 4);
    GXSetTevOrder(0, 255, 255, 4);
    fn_801EFB44(0, 11, 1, 5, 0);
    fn_801EF280(11, 1);
    GXSetZMode(1, 3, 1);
    GXSetZCompLoc(0);
    GXSetCullMode(2);
}
}