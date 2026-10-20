#pragma force_active on
struct Obj {
    int pad[2];
    unsigned int flags;
};

extern "C" void fn_40_30C9C(Obj* self) {
    self->flags |= 0x10000;
}
