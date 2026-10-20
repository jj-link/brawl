#pragma force_active on
typedef struct {
    int pad[2];
    int flags;
} FnObj;

extern "C" {
int fn_68_D700(FnObj *p)
{
    int v = (p->flags << 4) & (int)0xE0000000;
    return v >> 30;
}
}
