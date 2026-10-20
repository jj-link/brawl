#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} fn_27_122C30_obj;

extern "C" void fn_27_122C30(fn_27_122C30_obj *p)
{
    p->flags &= ~0x2000u;
}
