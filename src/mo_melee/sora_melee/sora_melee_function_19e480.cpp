#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FooBits {
    u32 w0;
    u32 w1;
    u32 pad0 : 6;
    s32 field : 3;
    u32 pad1 : 23;
};

extern "C" s32 fn_27_19E480(FooBits* p)
{
    return p->field;
}
