#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    unsigned int v;
} St;

int fn_68_D194(St *p)
{
    return (int)((p->v >> 27) << 29) >> 30;
}
}
