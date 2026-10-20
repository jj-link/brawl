#pragma force_active on
struct S {
    int a;
    int b;
    union {
        int raw;
        struct {
            unsigned : 6;
            signed field : 3;
            unsigned : 25;
        };
    };
};
extern "C" int fn_27_1A1064(S* p) { return p->field; }
