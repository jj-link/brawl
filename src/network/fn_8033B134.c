#pragma force_active on
struct Ctx {
    char pad0[0x24];
    int f24;
    int f28;
    char pad1[0x64 - 0x2C];
    int f64;
    char pad2[0x70 - 0x68];
    void (*f70)(int, int, int);
    int f74;
};

extern void fn_80337310(void *a, void *b);
extern struct Ctx *lbl_805A0F88;

void fn_8033B134(int arg0, int arg1) {
    struct Ctx *p;
    struct Ctx *q;
    if (arg0 == 0) {
        lbl_805A0F88->f64 = arg1;
        p = lbl_805A0F88;
        p->f28 = p->f24;
        q = lbl_805A0F88;
        q->f24 = 3;
        fn_80337310(q, p);
    } else {
        lbl_805A0F88->f28 = lbl_805A0F88->f24;
        lbl_805A0F88->f24 = 0;
    }
    if (lbl_805A0F88->f70 != 0) {
        lbl_805A0F88->f70(arg0, arg1, lbl_805A0F88->f74);
    }
}
