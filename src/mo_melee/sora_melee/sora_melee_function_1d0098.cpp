#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Fn27Obj {
    u32 pad0;
    u32 pad4;
    s32 field8;
};

extern "C" {
char* fn_27_1D0098(Fn27Obj* self, s32 idx)
{
    s32 i = (self->field8 >> 29) + idx;
    if (i >= 2) {
        i -= 2;
    }
    return (char*)self + i * 12 + 12;
}
}
