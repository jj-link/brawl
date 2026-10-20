#pragma force_active on
struct Foo {
    int a;
    int b;
    unsigned : 2;
    signed val : 2;
};

extern "C" int fn_47_4DB8(Foo *self) {
    return self->val;
}
