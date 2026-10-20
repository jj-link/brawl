#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    unsigned int flags;
} Obj;

void fn_73_A9B8(Obj *p)
{
    p->flags &= ~0x00080000;
}
}
