#pragma force_active on
struct fn27Entry {
    char pad[8];
    int field8;
};

extern "C" void* fn_27_1D5AF4(fn27Entry* self, int idx) {
    int i = (self->field8 >> 27) + idx;
    if (i >= 9) {
        i -= 9;
    }
    return (char*)self + i * 12 + 12;
}
