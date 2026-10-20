#pragma force_active on
struct fn27Obj {
    char pad[8];
    int field8;
};

extern "C" {
void* fn_27_1AFF44(fn27Obj* self, int idx) {
    int t = self->field8 >> 26;
    int n = t + idx;
    if (n >= 0x13) {
        n -= 0x13;
    }
    return (char*)self + n * 4 + 0xC;
}
}
