#pragma force_active on

extern "C" {
extern unsigned int lbl_804646A8[];
extern char lbl_804646B8[];
extern char lbl_80464710[];
}

struct Obj {
    char* vtbl;
    unsigned int w4, w8, wC;
    int x10;
    unsigned char b14, b15, b16;
    unsigned short s18;
};

extern "C" void fn_8015D984(Obj* p) {
    unsigned int b, a;
    unsigned int* q = lbl_804646A8;

    p->vtbl = lbl_80464710;
    a = *q++;
    b = *q++;
    p->w4 = a;
    p->w8 = b;
    p->wC = *q;
    p->vtbl = lbl_804646B8;
    p->x10 = 0;
    p->s18 = 0x3F;
    p->b14 = 0;
    p->b15 = 0;
    p->b16 = 0;
}
