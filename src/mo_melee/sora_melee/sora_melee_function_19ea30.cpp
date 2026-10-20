#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Bits {
    u32 a : 6;
    u32 b : 6;
    u32 c : 20;
};

extern "C" void fn_27_19EA30(u8* p, u32 v)
{
    Bits* f = (Bits*)(p + 8);
    f->b = v;
}
