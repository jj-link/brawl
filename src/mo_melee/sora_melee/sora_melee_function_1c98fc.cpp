#pragma force_active on
struct fn27Obj {
    char pad[0x18];
    int flags;
};

extern "C" {
void* fn_27_1C98FC(fn27Obj* self, int idx) {
    int i = (self->flags >> 28) + idx;
    if (i >= 4) {
        i -= 4;
    }
    return (char*)self + 0x1c + i * 12;
}
}
