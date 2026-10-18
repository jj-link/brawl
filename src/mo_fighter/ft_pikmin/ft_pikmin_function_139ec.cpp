#pragma force_active on
struct Foo {
    int a;
    int b;
    int c;
};

extern "C" int fn_113_139EC(Foo* self) {
    return self->c >> 27;
}
