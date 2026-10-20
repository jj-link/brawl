#pragma force_active on
struct FnObj27 {
    unsigned char pad[8];
    int field8;
};

extern "C" {
void* fn_27_1B019C(FnObj27* self, int idx) {
    int i = (self->field8 >> 27) + idx;
    if (i >= 8) {
        i -= 8;
    }
    return (char*)self + (i << 4) + 0xc;
}
}
