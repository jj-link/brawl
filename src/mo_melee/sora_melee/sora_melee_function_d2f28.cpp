#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 f : 3;
    u32 rest : 29;
} Bits;

extern "C" void fn_27_D2F28(char* p, u32 v)
{
    Bits* b = (Bits*)(p + 8);
    b->f = v;
}
