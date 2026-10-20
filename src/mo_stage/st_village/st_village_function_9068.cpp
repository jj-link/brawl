#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} St;

extern "C" {
int fn_70_9068(St *p)
{
    return (int)((p->flags >> 27 & 7) << 29) >> 30;
}
}
