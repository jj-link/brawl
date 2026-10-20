#pragma force_active on
struct Foo {
    int pad[2];
    unsigned int f : 6;
    unsigned int rest : 26;
};

extern "C" void fn_27_CF814(Foo* p, unsigned int v) {
    p->f = v;
}
