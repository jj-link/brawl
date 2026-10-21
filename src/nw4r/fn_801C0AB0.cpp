#pragma force_active on
extern "C" extern const float lbl_805A3530;
extern "C" extern const float lbl_805A3534;

struct Obj {
    float a;
    float b;
    unsigned int c;
    unsigned char d;
};

extern "C" void fn_801C0AB0(Obj* p) {
    p->a = lbl_805A3530;
    p->d = 1;
    p->b = lbl_805A3534;
    p->c = 0;
}
