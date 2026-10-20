#pragma force_active on
typedef unsigned int u32;

struct BitObj {
    u32 pad0;
    u32 pad4;
    u32 hi : 3;
    u32 rest : 29;
};

extern "C" void fn_27_1A74F0(BitObj* obj, u32 val)
{
    obj->hi = val;
}
