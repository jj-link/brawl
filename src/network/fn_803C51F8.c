#pragma force_active on
extern unsigned lbl_805A1210;
extern int lbl_805A1220;
extern void fn_803A976C(void*, int, int);
extern int fn_803AE4F4(int);
extern int fn_803C2A88(signed char);
extern int fn_803C2AB0(void);
extern int fn_803C2E54(signed char, int);
extern void fn_803C7CB8(int, int);
extern void fn_803C7D64(int, int);

typedef struct E {
    int a0; int a4; int a8; int aC; int a10; signed char a14; char pad[3]; int a18;
} E;

int fn_803C51F8(unsigned arg0, unsigned arg1) {
    E* e;
    int r;
    if (arg0 < lbl_805A1210 && lbl_805A1220 != 0) {
        e = (E*)(lbl_805A1220 + arg0 * 0x140);
    } else {
        e = 0;
    }
    if (e == 0 || e->a0 == 0) {
        return 0xB003;
    }
    if (e->a8 == 0) {
        return 0xB003;
    }
    if (e != 0 && e->a8 != 0) {
        fn_803C7D64(e->a8, 0);
    }
    r = fn_803C2E54(e->a14, arg1);
    if ((arg1 == 0 && r != 0) || (arg1 == 1 && r != 0 && r != 1)) {
        return fn_803C2AB0();
    }
    if (fn_803C2A88(e->a14) != 0) {
        return fn_803C2AB0();
    }
    if (fn_803AE4F4(e->a18) == 0) {
        fn_803C7CB8(e->a8, 0);
        fn_803C7D64(e->a8, 0);
        e->aC = 0;
        e->a10 = 0;
        e->a4 = 0;
        fn_803A976C((char*)e + 0x40, 0, 0xFF);
        return 0;
    }
    return fn_803C2AB0();
}
