#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[8];
    u32 field;
};

extern "C" {
int fn_48_BAC0(Obj* p)
{
    return ((s32)((p->field << 6) & 0xFE000000)) >> 26;
}
}
