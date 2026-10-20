#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_199FD8(Obj* p)
{
    return (s32)((p->unk8 << 4) & 0xF8000000) >> 28;
}
}
