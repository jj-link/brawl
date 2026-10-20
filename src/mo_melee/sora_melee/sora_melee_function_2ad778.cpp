#pragma force_active on
extern "C" {
struct Foo {
    int a;
    int b;
    int c;
};
int fn_27_2AD778(struct Foo* self) {
    return self->c >> 23;
}
}
