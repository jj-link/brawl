#pragma force_active on
struct Foo {
    int a;
    int b;
    unsigned : 9;
    unsigned target : 1;
    unsigned : 22;
};

extern "C" unsigned fn_27_390338(const Foo* p) {
    return p->target;
}
