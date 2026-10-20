#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 5;
    u32 field : 5;
    u32 lo : 22;
};

extern "C" void fn_27_CAA10(void* obj, u32 value)
{
    Bits* b = (Bits*)((char*)obj + 8);
    b->field = value;
}
