#pragma force_active on
struct FooObj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" void fn_27_1CF5AC(FooObj* self) {
    self->flags &= ~0x00400000;
}
