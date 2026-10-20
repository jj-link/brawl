#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 f : 6;
    u32 rest : 26;
};

extern "C" {
void fn_27_CAB88(void* obj, u32 val)
{
    Bits* p = (Bits*)((char*)obj + 8);
    p->f = val;
}
}
