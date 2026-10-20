#pragma force_active on
struct Fn27Obj {
    char pad[0x8];
    int f8;
};

extern "C" {
void* fn_27_1B08A0(Fn27Obj* self, int idx) {
    int i = (self->f8 >> 28) + idx;
    if (i >= 7) {
        i -= 7;
    }
    return (char*)self + i * 0x14 + 0xC;
}
}
