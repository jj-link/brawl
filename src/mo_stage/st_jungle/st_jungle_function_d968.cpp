#pragma force_active on
struct Foo {
    int a;
    int b;
    union {
        int val;
        struct {
            unsigned int : 3;
            signed int field : 3;
        };
    };
};

extern "C" int fn_51_D968(Foo* obj) {
    return obj->field;
}
