#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FnObj {
    u32 unk0;
    s32 unk4;
};

extern "C" u32 fn_27_2BC0FC(FnObj* p)
{
    return (u32)(p->unk4 >> 27) >> 31;
}
