#pragma force_active on
struct FlagObj {
    int pad[2];
    unsigned int flags;
};

extern "C" void fn_74_6994(struct FlagObj *p)
{
    p->flags &= ~0x02000000u;
}
