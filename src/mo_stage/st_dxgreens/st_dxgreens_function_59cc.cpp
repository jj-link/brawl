#pragma force_active on
struct S
{
    unsigned int a[2];
    unsigned int flags;
};

extern "C" void fn_79_59CC(S* p)
{
    p->flags &= ~0x2000u;
}
