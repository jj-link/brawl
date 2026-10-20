#pragma force_active on
typedef unsigned int u32;

struct BitsHolder {
    u32 pad[2];
    u32 bits : 3;
    u32 rest : 29;
};

extern "C" {
void fn_27_C98CC(BitsHolder *p, u32 v)
{
    p->bits = v;
}
}
