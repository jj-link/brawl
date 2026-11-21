#pragma force_active on
extern "C" void netReport__FPCce(const char*, ...);
extern "C" int fn_8033CA34(int, int, int);

extern char lbl_8045F7A8[];
extern char lbl_8059E7A8[5];
extern char lbl_8059E7B0[5];
extern int lbl_805A0434;

struct Foo {
    char pad0[0x3498];
    int v;
};

extern "C" int fn_8014B874(int arg0) {
    int a;
    int b;
    int d;
    netReport__FPCce(lbl_8045F7A8 + 0x1284, arg0);
    a = fn_8033CA34(arg0, (int)lbl_8059E7A8, -1);
    b = fn_8033CA34(arg0, (int)lbl_8059E7B0, -1);
    d = ((Foo*)lbl_805A0434)->v - a;
    if (d < 0) d = -d;
    netReport__FPCce(lbl_8045F7A8 + 0x12a8, d, b);
    if (b >= 0x3c) {
        netReport__FPCce(lbl_8045F7A8 + 0x12e8, 0x3c);
        return 0x7fffffff;
    }
    if (d > 0x28) {
        netReport__FPCce(lbl_8045F7A8 + 0x1324, d);
        return 0;
    }
    return 0x7fffffff;
}
