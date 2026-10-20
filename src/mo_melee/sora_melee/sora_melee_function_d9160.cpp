#pragma force_active on
struct Fn27Self {
    int pad[2];
    int field8;
};

extern "C" {
void* fn_27_D9160(Fn27Self* self, int idx) {
    int v = (self->field8 >> 24) + idx;
    if (v >= 0x5c) {
        v -= 0x5c;
    }
    return (char*)self + v * 0x30 + 0xc;
}
}
