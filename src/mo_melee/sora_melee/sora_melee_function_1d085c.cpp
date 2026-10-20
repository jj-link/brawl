#pragma force_active on
struct FlagHolder {
    unsigned int pad[2];
    unsigned int flags;
};

extern "C" {
void fn_27_1D085C(FlagHolder *p)
{
    p->flags &= ~0x80000u;
}
}
