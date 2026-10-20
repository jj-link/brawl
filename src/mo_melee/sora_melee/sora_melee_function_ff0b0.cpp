#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 pad[2];
    u32 a : 2;
    u32 b : 2;
    u32 c : 28;
};

extern "C" void fn_27_FF0B0(Flags* obj, u32 val)
{
    obj->b = val;
}
