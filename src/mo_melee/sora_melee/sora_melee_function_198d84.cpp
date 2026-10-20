#pragma force_active on
struct Obj {
    unsigned int pad[2];
    unsigned int value;
};

extern "C" void fn_27_198D84(Obj* self, unsigned int value) {
    self->value = __rlwimi(self->value, value, 23, 6, 8);
}
