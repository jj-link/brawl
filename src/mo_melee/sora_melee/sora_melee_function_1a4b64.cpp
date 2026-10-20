#pragma force_active on
typedef unsigned int u32;

extern "C" extern char lbl_27_data_35528[];

struct Obj {
    void* a;
    void* b;
    u32 c;
};

extern "C" void fn_27_1A4B64(Obj* o) {
    u32 v = o->c;
    o->a = lbl_27_data_35528;
    o->b = lbl_27_data_35528 + 0x48;
    o->c = v & 0x7FFFF;
}
