#pragma force_active on
extern "C" {
typedef struct {
    void *a;
    void *b;
    unsigned int flags;
} FlagObj;

void fn_79_5920(FlagObj *p)
{
    p->flags &= 0xFFFFDFFF;
}
}
