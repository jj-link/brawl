#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 word0;
    u32 word1;
    u32 pad0 : 10;
    u32 field : 5;
    u32 pad1 : 17;
};

extern "C" void fn_27_D37AC(Bits *obj, u32 val)
{
    obj->field = val;
}
