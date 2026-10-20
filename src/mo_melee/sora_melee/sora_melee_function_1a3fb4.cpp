#pragma force_active on
struct Foo {
    int a;
    int b;
    union {
        int val;
        struct {
            unsigned low : 10;
            signed mid : 10;
            unsigned high : 12;
        };
    } c;
};

extern "C" int fn_27_1A3FB4(Foo* p) {
    return p->c.mid;
}
