#pragma force_active on
struct Foo {
    int a;
    int b;
    unsigned int : 4;
    signed int f : 2;
};

extern "C" int fn_67_51C8(struct Foo *p) {
    return p->f;
}
