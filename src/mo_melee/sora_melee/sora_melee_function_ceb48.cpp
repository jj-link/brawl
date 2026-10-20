#pragma force_active on
extern "C" {

struct Foo {
    int a;
    int b;
    signed int m;
};

signed int fn_27_CEB48(const Foo* self) {
    return (self->m >> 26);
}

}
