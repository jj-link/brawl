#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad0;
    u32 pad1;
    u32 hi : 5;
    u32 lo : 27;
};

extern "C" {
void fn_27_CAEB8(Bits *obj, u32 val)
{
    obj->hi = val;
}
}
