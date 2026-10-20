#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct ftData_1B2270 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_1B2270(ftData_1B2270* p)
{
    s32 v = (s32)(p->unk8 << 8);
    s32 m = v & (s32)0xF8000000;
    return m >> 28;
}
}
