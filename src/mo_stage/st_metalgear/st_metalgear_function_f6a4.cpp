#pragma force_active on
struct Obj {
    int pad[2];
    unsigned int a : 2;
    unsigned int b : 30;
};

extern "C" void fn_71_F6A4(Obj* p, unsigned int v) {
    p->a = v;
}
