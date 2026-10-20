#pragma force_active on
extern "C" {

struct S {
    int a;
    int b;
    int c;
};

int fn_27_CDA08(S* self) {
    return (self->c >> 25) & 1;
}

}
