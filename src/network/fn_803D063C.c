#pragma force_active on
typedef struct {
    unsigned char r, g, b, a;
} Color4;

typedef struct {
    unsigned char unk0;
    int unk4;
    int unk8;
    int unkC;
    Color4 unk10;
    unsigned char unk14;
} Arg;

void GXSetAlphaCompare(int, int, int, int, int);
void GXSetBlendMode(int, int, int, int);
void GXSetZMode(int, int, int);
void GXSetZCompLoc(unsigned char);
void fn_801F471C(int);
void fn_801F4748(int);
void fn_801F4880(int);
void fn_801F48AC(int, int);
void fn_801F3AFC(int);
void fn_801F3F20(int, int, int);
void GXSetTevOrder(int, int, int, int);
void fn_801F3C30(int, int, int, int, int);
void fn_801F3CB0(int, int, int, int, int, int);
void fn_801F3C70(int, int, int, int, int);
void fn_801F3D08(int, int, int, int, int, int);
void fn_803D0938(void*);
void fn_801EFB10(void);
void fn_801EF280(int, int);
void fn_801EFB44(int, int, int, int, int);
void GXSetNumTexGens(int);
void GXSetNumChans(int);
void GXSetChanCtrl(int, int, int, int, int, int, int);
void fn_801F2494(int, Color4*);
void fn_801F256C(int, Color4*);

extern char lbl_8041AD18[];
extern char lbl_8041AD3C[];
extern unsigned char lbl_805A49F0;
extern unsigned char lbl_805A49F1;
extern unsigned char lbl_805A49F2;
extern unsigned char lbl_805A49F3;

void fn_803D063C(Arg arg) {
    Color4 c0;
    Color4 c1;

    GXSetAlphaCompare(4, 0, 1, 0, 0);
    GXSetBlendMode(1, 4, 5, 3);
    GXSetZMode(1, 3, 1);
    GXSetZCompLoc(arg.unk14);
    fn_801F471C(1);
    fn_801F4748(1);
    fn_801F4880(0);
    fn_801F48AC(0, 0);
    if (arg.unk0) {
        fn_801F3AFC(1);
        fn_801F3F20(1, 0, 0);
        GXSetTevOrder(1, 0xFF, 0xFF, 4);
        fn_801F3C30(1, 0xF, 0, 0xA, 0xF);
        fn_801F3CB0(1, 0, 0, 0, 1, 0);
        fn_801F3C70(1, 7, 7, 7, 0);
        fn_801F3D08(1, 0, 0, 0, 1, 0);
        fn_803D0938(lbl_8041AD18);
        fn_801EFB10();
        fn_801EF280(9, 2);
        fn_801EF280(0xA, 2);
        fn_801EF280(0xD, 2);
        fn_801EFB44(0, 9, 1, 3, 8);
        fn_801EFB44(0, 0xA, 0, 3, 0xE);
        fn_801EFB44(0, 0xD, 1, 3, 0xD);
        GXSetNumTexGens(1);
        GXSetNumChans(1);
        GXSetChanCtrl(0, 1, 0, 0, arg.unk4, arg.unk8, arg.unkC);
        GXSetChanCtrl(2, 0, 0, 0, 0, 0, 2);
        c0 = arg.unk10;
        fn_801F2494(0, &c0);
        c1.r = lbl_805A49F0;
        c1.g = lbl_805A49F1;
        c1.b = lbl_805A49F2;
        c1.a = lbl_805A49F3;
        fn_801F256C(0, &c1);
    } else {
        fn_803D0938(lbl_8041AD3C);
        fn_801EFB10();
        fn_801EF280(9, 2);
        fn_801EF280(0xA, 2);
        fn_801EF280(0xD, 2);
        fn_801EFB44(0, 9, 1, 3, 8);
        fn_801EFB44(0, 0xA, 0, 3, 0xE);
        fn_801EFB44(0, 0xD, 1, 3, 0xD);
        GXSetNumTexGens(1);
        GXSetNumChans(0);
    }
}
