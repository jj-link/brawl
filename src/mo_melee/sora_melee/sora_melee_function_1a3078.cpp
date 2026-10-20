#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Holder {
    char pad[8];
    u32 field;
};

extern "C" {
s32 fn_27_1A3078(Holder *p)
{
    u32 v = p->field;
    v = (v << 3) | (v >> 29);
    return (s32)(v & 0xF0000000) >> 29;
}
}
