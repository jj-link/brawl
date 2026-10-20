#pragma force_active on
extern "C" {
typedef struct {
    int a;
    int b;
    unsigned int flags;
} FnObj;

void fn_48_BF54(FnObj *p)
{
    p->flags |= 0x2000;
}
}
