#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} St;

extern "C" void fn_62_A568(St *p)
{
    p->flags &= 0xFDFFFFFFu;
}
