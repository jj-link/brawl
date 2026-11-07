#pragma force_active on
typedef unsigned char u8;

typedef struct Color4 {
    u8 r, g, b, a;
} Color4;

extern void GXSetNumTevStages(int);
extern void GXSetTevOrder(int, int, int, int);
extern void fn_801F3F20(int, int, int);
extern void fn_801F3C30(int, int, int, int, int);
extern void fn_801F3C70(int, int, int, int, int);
extern void fn_801F3CB0(int, int, int, int, int, int);
extern void fn_801F3D08(int, int, int, int, int, int);
extern void fn_801F3D60(int, Color4);

extern Color4 lbl_8041AE50[];
extern u8 lbl_805A4A50;
extern u8 lbl_805A4A51;
extern u8 lbl_805A4A52;
extern u8 lbl_805A4A53;
extern u8 lbl_805A4A54;
extern u8 lbl_805A4A55;
extern u8 lbl_805A4A56;
extern u8 lbl_805A4A57;
extern u8 lbl_805A4A58;
extern u8 lbl_805A4A59;
extern u8 lbl_805A4A5A;
extern u8 lbl_805A4A5B;

void fn_803D3584(int a, int b) {
    Color4 c;
    Color4 d;

    GXSetNumTevStages(3);
    fn_801F3F20(0, 1, 1);
    GXSetTevOrder(0, 0, 0, 4);
    fn_801F3C30(0, 0xF, 2, 8, 0xF);
    fn_801F3C70(0, 7, 7, 7, 4);
    fn_801F3CB0(0, 0, 0, 0, 1, 0);
    fn_801F3D08(0, 0, 0, 0, 1, 0);
    fn_801F3F20(1, 3, 3);
    GXSetTevOrder(1, 0, 0, 4);
    fn_801F3C30(1, 0xF, 4, 8, 0);
    fn_801F3C70(1, 7, 7, 7, 0);
    fn_801F3CB0(1, 0, 0, 0, 1, 0);
    fn_801F3D08(1, 0, 0, 0, 1, 0);
    fn_801F3F20(2, 2, 2);
    GXSetTevOrder(2, 0, 0, 4);
    fn_801F3C30(2, 0xF, 0xC, 8, 0);
    fn_801F3C70(2, 7, 7, 7, 0);
    fn_801F3CB0(2, 0, 0, 0, 1, 0);
    fn_801F3D08(2, 0, 0, 0, 1, 0);
    switch (b) {
    case 9:
        c.r = lbl_805A4A50;
        c.g = lbl_805A4A51;
        c.b = lbl_805A4A52;
        c.a = lbl_805A4A53;
        break;
    case 20:
        c.r = lbl_805A4A54;
        c.g = lbl_805A4A55;
        c.b = lbl_805A4A56;
        c.a = lbl_805A4A57;
        break;
    default:
        c.r = lbl_805A4A58;
        c.g = lbl_805A4A59;
        c.b = lbl_805A4A5A;
        c.a = lbl_805A4A5B;
        break;
    }
    fn_801F3D60(1, c);
    d = lbl_8041AE50[a];
    fn_801F3D60(2, d);
}
