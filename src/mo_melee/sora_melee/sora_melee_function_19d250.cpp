#pragma force_active on
typedef unsigned int u32;

struct Word8 {
    u32 a : 8;
    u32 b : 4;
    u32 c : 20;
};

extern "C" void fn_27_19D250(void* p, u32 v)
{
    Word8* w = (Word8*)((char*)p + 8);
    w->b = v;
}
