#pragma force_active on
typedef struct {
    int pad0;
    int pad1;
    unsigned int flags;
} St;

extern "C" {
int fn_62_6038(St *p)
{
    return (int)((p->flags << 2) & 0xE0000000) >> 30;
}
}
