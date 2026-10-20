#pragma force_active on
struct Foo {
    int a;
    int b;
    unsigned : 8;
    signed int c : 4;
    unsigned : 12;
};

extern "C" int fn_47_4F7C(struct Foo* p) {
    return p->c;
}
