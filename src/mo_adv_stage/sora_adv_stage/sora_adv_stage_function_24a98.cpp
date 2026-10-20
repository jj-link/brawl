#pragma force_active on
struct Foo {
    int w0;
    int w1;
    unsigned int top : 2;
    unsigned int rest : 30;
};

extern "C" {
void fn_40_24A98(Foo* p, unsigned int v) {
    p->top = v;
}
}
