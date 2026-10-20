#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 w0;
    u32 w1;
    u32 a : 5;
    u32 b : 5;
    u32 c : 22;
} BitfieldStruct;

extern "C" void fn_27_19ED60(BitfieldStruct *p, u32 v)
{
    p->b = v;
}
