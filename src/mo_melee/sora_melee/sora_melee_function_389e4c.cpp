#pragma force_active on
struct S {
    unsigned int reserved[2];
    unsigned int value;
};

extern "C" void fn_27_389E4C(S* self, unsigned int value) {
    self->value = __rlwimi(self->value, value, 20, 8, 11);
}
