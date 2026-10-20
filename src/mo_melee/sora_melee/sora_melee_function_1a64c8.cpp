#pragma force_active on
struct Obj {
    void* a;
    void* b;
    unsigned int c;
};

extern "C" {
extern char lbl_27_data_34118[];
}

extern "C" void fn_27_1A64C8(Obj* o) {
    unsigned int f = o->c;
    char* base = lbl_27_data_34118;
    o->a = base;
    o->b = base + 0x48;
    o->c = f & 1;
}
