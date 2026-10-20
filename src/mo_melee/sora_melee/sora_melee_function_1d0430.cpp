#pragma force_active on
typedef int s32;

struct Fn27Obj {
    char pad[8];
    s32 unk8;
};

extern "C" {
char* fn_27_1D0430(Fn27Obj* self, s32 idx)
{
    s32 n = self->unk8 >> 28;
    s32 t = n + idx;
    if (t >= 5) {
        t -= 5;
    }
    return (char*)self + t * 12 + 12;
}
}
