#pragma force_active on
struct Fn27Obj {
    char pad[8];
    unsigned int flags;
};

extern "C" {
void fn_27_CBB9C(Fn27Obj* self) {
    self->flags &= ~0x80000;
}
}
