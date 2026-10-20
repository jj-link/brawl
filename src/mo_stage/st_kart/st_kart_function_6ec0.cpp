#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
};

extern "C" void fn_49_6EC0(S* p, unsigned int v) {
    p->b = v;
}
