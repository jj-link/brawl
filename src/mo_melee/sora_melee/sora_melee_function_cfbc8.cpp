#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    struct {
        u32 hi : 12;
        u32 f : 6;
        u32 lo : 14;
    } bits;
} FnObj;

extern "C" void fn_27_CFBC8(FnObj* p, u32 v)
{
    p->bits.f = v;
}
