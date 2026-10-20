#pragma force_active on
typedef struct {
    int pad0;
    int pad1;
    unsigned int flags;
} Obj;

extern "C" {
void fn_71_A110(Obj *p)
{
    p->flags |= 0x02000000;
}
}
