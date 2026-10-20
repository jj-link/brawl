#pragma force_active on
struct FooObj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_1D0BF4(FooObj* self) {
    self->flags &= 0xFFF7FFFFu;
}
}
