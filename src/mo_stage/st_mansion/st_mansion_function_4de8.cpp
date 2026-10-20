#pragma force_active on
typedef struct {
    int a;
    int b;
    unsigned int flags;
} FnObj47;

extern "C" {
void fn_47_4DE8(FnObj47 *p)
{
    p->flags |= 0x02000000;
}
}
