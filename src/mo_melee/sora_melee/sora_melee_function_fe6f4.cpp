#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

struct Fn27Obj {
    char pad[8];
    s32 unk8;
};

extern "C" void* fn_27_FE6F4(Fn27Obj* self, u32 idx)
{
    s32 s = self->unk8 >> 28;
    s32 n = s + (s32)idx;
    if (n >= 5) {
        n -= 5;
    }
    return (char*)self + n * 12 + 12;
}
