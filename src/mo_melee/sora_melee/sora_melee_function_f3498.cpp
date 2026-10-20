#pragma force_active on
struct Obj {
    char pad[0x18];
    int unk18;
};

extern "C" void* fn_27_F3498(Obj* self, int idx) {
    int i = (self->unk18 >> 29) + idx;
    if (i >= 3) {
        i -= 3;
    }
    return (char*)self + 0x1c + i * 12;
}
