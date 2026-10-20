#pragma force_active on
extern "C" {

struct A {
    int a;
    int b;
    int c;
};

int fn_27_19DB4C(A *self) {
    return (self->c >> 16) & 1;
}

}
