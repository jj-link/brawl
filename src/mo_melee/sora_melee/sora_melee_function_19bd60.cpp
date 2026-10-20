#pragma force_active on
typedef unsigned int u32;

struct FnStruct27 {
    char pad[8];
    u32 flags;
};

extern "C" void fn_27_19BD60(FnStruct27 *p)
{
    p->flags &= 0xFDFFFFFF;
}
