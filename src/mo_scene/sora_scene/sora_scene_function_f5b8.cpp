#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" char lbl_1_data_4B10[];
extern "C" char lbl_1_data_4C00[];

struct Obj {
    void* a;
    void* b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
};

extern "C" {
void fn_1_F5B8() {
    Obj* p = (Obj*)__nw__FUlQ25Heaps8HeapType(0x30, 0x2e);
    if (p) {
        p->a = lbl_1_data_4B10;
        p->b = lbl_1_data_4C00;
        p->c = 0;
        p->d = 0;
        p->e = 0;
        p->f = 0;
        p->g = 0;
        p->h = 0;
    }
}
}
