#pragma force_active on
struct Obj {
    void* vtbl;
    unsigned int pad[3];
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

extern char lbl_27_data_46658[];

extern "C" void fn_27_281864(Obj* o, unsigned int a, unsigned int b, unsigned int c) {
    o->a = a;
    o->vtbl = lbl_27_data_46658;
    o->b = b;
    o->c = c;
}
