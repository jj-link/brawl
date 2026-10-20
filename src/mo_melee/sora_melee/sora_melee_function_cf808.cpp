#pragma force_active on
struct Foo {
    int a;
    int b;
    int c;
};

extern "C" int fn_27_CF808(Foo* self) {
    return self->c >> 26;
}
