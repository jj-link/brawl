#pragma force_active on
typedef struct {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int flags;
} Obj;

extern "C" void fn_67_5044(Obj *p)
{
    p->flags &= 0xFDFFFFFF;
}
