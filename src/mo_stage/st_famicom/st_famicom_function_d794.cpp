#pragma force_active on
typedef unsigned long u32;

struct FnObj68 {
    u32 pad[2];
    u32 flags;
};

extern "C" void fn_68_D794(struct FnObj68 *p)
{
    p->flags |= 0x00080000;
}
