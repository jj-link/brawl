#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" void fn_27_19F258(Data* self) {
    self->flags &= ~0x2000u;
}
