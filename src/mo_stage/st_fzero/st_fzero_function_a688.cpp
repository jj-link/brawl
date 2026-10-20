#pragma force_active on
struct St {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_61_A688(St *p)
{
    p->flags &= ~0x02000000;
}
}
