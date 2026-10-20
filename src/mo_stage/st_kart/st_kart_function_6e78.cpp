#pragma force_active on
struct St49 {
    unsigned int pad[2];
    unsigned int flags;
};

extern "C" void fn_49_6E78(St49 *p)
{
    p->flags &= ~0x02000000u;
}
