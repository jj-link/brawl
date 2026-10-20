#pragma force_active on
struct FnObj27 {
    char pad[8];
    unsigned int flags;
};

extern "C" {
void fn_27_D3500(FnObj27 *p)
{
    p->flags &= ~0x00400000;
}
}
