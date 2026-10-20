#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[8];
    u32 field8;
};

extern "C" {
s32 fn_27_19EBB8(struct Obj *p)
{
    return (s32)(((p->field8 >> 27) & 7) << 29) >> 30;
}
}
