#pragma force_active on
struct Obj {
    char pad[8];
    int field8;
};

extern "C" {
void* fn_27_1B0EC4(Obj* self, int idx) {
    int i = (self->field8 >> 28) + idx;
    if (i >= 5) {
        i -= 5;
    }
    return (char*)self + (i << 3) + 0xC;
}
}
