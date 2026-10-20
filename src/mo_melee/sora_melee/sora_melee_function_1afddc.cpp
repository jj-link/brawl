#pragma force_active on
struct FnObj {
    char pad[8];
    int field8;
};

extern "C" void* fn_27_1AFDDC(FnObj* self, int idx) {
    int off = self->field8 >> 22;
    int n = off + idx;
    if (n >= 0x122) {
        n -= 0x122;
    }
    return (char*)self + 0xc + n * 4;
}
