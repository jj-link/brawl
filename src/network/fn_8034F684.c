#pragma force_active on
extern int fn_803C2F08(void);
extern int fn_803353F4(int, int, int);
extern void fn_803C2F1C(int, int);
extern int fn_803995F8(int *);
extern void fn_80335638(int, const char *, ...);
extern void fn_803C2FE4(void);
extern void fn_80335450(int, int, int);
extern int lbl_805A0FBC;
extern int lbl_805A0FC0;
extern int lbl_805A0FC4;
extern const char lbl_8048D2A0[];
extern const char lbl_8048D2C4[];

unsigned long long fn_8034F684(void) {
    int r30, r29, r28;
    if (lbl_805A0FBC == 0) {
        r30 = fn_803C2F08();
        r29 = fn_803353F4(3, 0x4000, 0x20);
        r28 = fn_803353F4(3, 0x8000, 0x20);
        lbl_805A0FBC = 1;
        if (r30 != 1)
            fn_803C2F1C(r28, 0x8000);
        if (fn_803995F8(&lbl_805A0FC0) == 0)
            fn_80335638(0x08000000, lbl_8048D2A0, lbl_805A0FC0, lbl_805A0FC4);
        else {
            fn_80335638(0x08000000, lbl_8048D2C4);
            lbl_805A0FC4 = 0;
            lbl_805A0FC0 = 0;
        }
        if (r30 != 1)
            fn_803C2FE4();
        fn_80335450(3, r29, 0);
        fn_80335450(3, r28, 0);
    }
    return ((unsigned long long)(unsigned int)lbl_805A0FC0 << 32) | (unsigned int)lbl_805A0FC4;
}