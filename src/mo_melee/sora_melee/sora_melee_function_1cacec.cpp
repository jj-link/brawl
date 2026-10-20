#pragma force_active on
struct Fn27Obj {
    char pad[0x18];
    int unk18;
};

extern "C" {
void* fn_27_1CACEC(Fn27Obj* self, int idx) {
    int i = (self->unk18 >> 28) + idx;
    if (i >= 4) {
        i -= 4;
    }
    return (char*)self + i * 12 + 0x1c;
}
}
