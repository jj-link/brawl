#pragma force_active on
struct Object {
    unsigned char pad0[0x149];
    unsigned char count;
    unsigned char pad1[0x32C - 0x14A];
    bool flags[24];
};

extern "C" void fn_27_1F299C(Object* self, int index) {
    if (index < 0 || (unsigned int)index >= 24 || !self->flags[index])
        return;

    self->flags[index] = false;
    --self->count;
}
