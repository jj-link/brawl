#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 pad0;
    u32 pad1;
    unsigned int pad : 5;
    unsigned int f : 5;
    unsigned int rest : 22;
};

extern "C" void fn_27_1A4CF8(void *obj, unsigned int val)
{
    Flags *p = (Flags *)obj;
    p->f = val & 0x1F;
}
