#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} Obj;

extern "C" {
void fn_47_4D44(Obj *p)
{
    p->flags &= 0xFDFFFFFFu;
}
}
