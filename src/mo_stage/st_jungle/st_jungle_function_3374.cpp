#pragma force_active on
typedef unsigned char u8;

struct FnObj51 {
    char pad[0x6c];
    u8 flags;
};

extern "C" void fn_51_3374(FnObj51 *p)
{
    unsigned int v = p->flags;
    v &= ~0x08u;
    p->flags = (u8)v;
}
