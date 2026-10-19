#pragma force_active on
struct Fn474D64Src {
    char pad[8];
    int field;
};

extern "C" void* fn_47_4D64(Fn474D64Src* self, int index) {
    int i = (self->field >> 30) + index;
    if (i >= 1) {
        i -= 1;
    }
    return (char*)self + i * 0x68 + 0xc;
}
