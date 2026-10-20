#pragma force_active on
extern "C" {
struct FlagObj {
    int pad[2];
    unsigned int flags;
};

void fn_79_5B2C(struct FlagObj *p)
{
    p->flags &= ~0x02000000;
}
}
