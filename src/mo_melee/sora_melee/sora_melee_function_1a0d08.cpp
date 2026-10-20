#pragma force_active on
extern "C" {

struct Foo {
    int a;
    int b;
    signed f0 : 3;
    signed f1 : 3;
    signed f2 : 26;
};

int fn_27_1A0D08(Foo* self) {
    return self->f1;
}

}
