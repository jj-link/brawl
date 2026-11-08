#pragma force_active on

typedef unsigned char u8;

typedef struct {
    u8 r, g, b, a;
} Color4;

extern void GXSetNumTevStages(int);
extern void GXSetTevOrder(int, int, int, int);
extern void fn_801F3F20(int, int, int);
extern void fn_801F3C30(int, int, int, int, int);
extern void fn_801F3C70(int, int, int, int, int);
extern void fn_801F3CB0(int, int, int, int, int, int);
extern void fn_801F3D08(int, int, int, int, int, int);
extern void fn_801F3D60(int, const void *);

extern u8 lbl_8041AE88[];
extern u8 lbl_8041AE94[];

void fn_803D333C(int a) {
    Color4 c0;
    Color4 c1;
    u8 *p;

    GXSetNumTevStages(3);
    fn_801F3F20(0, 1, 1);
    GXSetTevOrder(0, 0, 0, 4);
    fn_801F3C30(0, 0xF, 2, 8, 0xF);
    fn_801F3C70(0, 7, 7, 7, 4);
    fn_801F3CB0(0, 0, 0, 0, 1, 0);
    fn_801F3D08(0, 0, 0, 0, 1, 0);
    fn_801F3F20(1, 3, 2);
    GXSetTevOrder(1, 0, 0, 4);
    fn_801F3C30(1, 0xF, 4, 8, 0);
    fn_801F3C70(1, 7, 7, 7, 0);
    fn_801F3CB0(1, 0, 0, 0, 1, 0);
    fn_801F3D08(1, 0, 0, 0, 1, 0);
    fn_801F3F20(2, 2, 3);
    GXSetTevOrder(2, 0, 0, 4);
    fn_801F3C30(2, 0xF, 0xC, 8, 0);
    fn_801F3C70(2, 7, 7, 7, 0);
    fn_801F3CB0(2, 0, 0, 0, 1, 0);
    fn_801F3D08(2, 0, 0, 0, 1, 0);

    p = &lbl_8041AE88[a * 4];
    c0.r = p[0];
    c0.g = p[1];
    c0.b = p[2];
    c0.a = p[3];
    fn_801F3D60(1, &c0);

    p = &lbl_8041AE94[a * 4];
    c1.r = p[0];
    c1.g = p[1];
    c1.b = p[2];
    c1.a = p[3];
    fn_801F3D60(2, &c1);
}