#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
} FnZeroPair;

extern "C" void fn_27_27C1D8(FnZeroPair* p)
{
    p->unk0 = 0;
    p->unk4 = 0;
}
