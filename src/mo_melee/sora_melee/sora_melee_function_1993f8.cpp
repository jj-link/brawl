#pragma force_active on
struct Fn27Obj {
    void* a;
    void* b;
    unsigned int c;
};

extern "C" {
extern unsigned char lbl_27_data_39F78[];
}

extern "C" void fn_27_1993F8(Fn27Obj* p) {
    unsigned int v = p->c;
    unsigned char* base = lbl_27_data_39F78;
    p->a = base;
    p->b = base + 0x48;
    p->c = v & 0x7FFFF;
}
