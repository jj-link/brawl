#pragma force_active on
struct Foo {
    int a;
    int b;
    int c;
};

extern "C" int fn_27_1A387C(const Foo *p) {
    return p->c >> 22;
}
