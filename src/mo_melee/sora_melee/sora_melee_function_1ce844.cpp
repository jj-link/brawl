#pragma force_active on
struct Fn27Obj {
    char pad[0x18];
    int unk18;
};

extern "C" {
void* fn_27_1CE844(Fn27Obj* self, int idx)
{
    int i = (self->unk18 >> 25) + idx;
    if (i >= 0x20) {
        i -= 0x20;
    }
    return (char*)self + 0x1c + i * 12;
}
}
