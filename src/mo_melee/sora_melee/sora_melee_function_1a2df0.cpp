#pragma force_active on
typedef unsigned int u32;

extern char lbl_27_data_3DFE8[];

struct Obj {
    void* a;
    void* b;
    u32 c;
};

extern "C" void fn_27_1A2DF0(Obj* p) {
    u32 c = p->c;
    char* base = lbl_27_data_3DFE8;
    char* end = base + 0x48;
    p->a = base;
    p->b = end;
    p->c = c & 0xFFFF;
}
