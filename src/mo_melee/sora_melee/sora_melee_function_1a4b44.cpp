#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_1A4B44(Fn27Obj* p)
{
    s32 v = (s32)(((p->unk8 >> 10) & 0xFF) << 24);
    return v >> 25;
}
