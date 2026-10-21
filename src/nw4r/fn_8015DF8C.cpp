#pragma force_active on

extern "C" {
extern char lbl_80464710[];
extern char lbl_80464778[];
extern unsigned int lbl_80464768[];
}

struct Obj {
    void* vtbl;
    unsigned int w4, w8, wC;
    int x10, x14;
    unsigned short s18, s1A;
};

extern "C" void fn_8015DF8C(Obj* p) {
    unsigned int b, a;
    unsigned int* q = lbl_80464768;

    p->vtbl = lbl_80464710;
    a = *q++;
    b = *q++;
    p->w4 = a;
    p->w8 = b;
    p->wC = *q;
    p->vtbl = lbl_80464778;
    p->x10 = 0;
    p->x14 = 0;
    p->s18 = 0;
    p->s1A = 0xFFFF;
}
