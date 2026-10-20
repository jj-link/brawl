#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} St71;

extern "C" {
void fn_71_F6E4(St71 *p)
{
    p->flags &= ~0x02000000u;
}
}
