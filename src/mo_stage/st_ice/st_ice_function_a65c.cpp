#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 pad[2];
    u32 a : 4;
    u32 f : 2;
    u32 rest : 26;
} Bits;

extern "C" {
void fn_62_A65C(Bits *obj, u32 val)
{
    obj->f = val;
}
}
