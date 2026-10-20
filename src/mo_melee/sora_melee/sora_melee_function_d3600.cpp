#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Fields {
    u32 pad0;
    u32 pad1;
    u32 a : 5;
    s32 b : 5;
    u32 c : 22;
};

extern "C" s32 fn_27_D3600(Fields* p)
{
    return p->b;
}
