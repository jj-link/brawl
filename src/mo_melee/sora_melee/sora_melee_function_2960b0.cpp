#pragma force_active on
struct Foo {
    int a;
    int b;
    unsigned int : 6;
    int field : 6;
    unsigned int : 20;
};

extern "C" int fn_27_2960B0(Foo* p) {
    return p->field;
}
