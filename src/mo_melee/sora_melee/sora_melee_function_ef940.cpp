#pragma force_active on
typedef int s32;

struct Fn27Obj {
    char pad[0x18];
    s32 unk18;
};

extern "C" void* fn_27_EF940(Fn27Obj* self, s32 idx)
{
    s32 i = (self->unk18 >> 30) + idx;
    if (i >= 1) {
        i--;
    }
    return (char*)self + i * 12 + 0x1c;
}
