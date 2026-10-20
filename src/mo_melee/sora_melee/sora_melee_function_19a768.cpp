#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 w0;
    u32 w1;
    u32 pad : 3;
    u32 f : 3;
    u32 rest : 26;
};

extern "C" {
void fn_27_19A768(Bits *obj, u32 val)
{
    obj->f = val;
}
}
