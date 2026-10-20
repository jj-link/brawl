#pragma force_active on
typedef unsigned int u32;

struct fnWork {
    void* a;
    void* b;
    u32 c;
};

extern "C" {
extern char lbl_27_data_3C170[];
}

extern "C" void fn_27_1A558C(fnWork* w) {
    u32 v = w->c;
    char* base = lbl_27_data_3C170;
    w->a = base;
    w->b = base + 0x48;
    w->c = v & 0x7FFFF;
}
