#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int a : 5;
    unsigned int b : 27;
};

extern "C" void fn_27_1A2160(S* p, unsigned int v) {
    p->a = v;
}
