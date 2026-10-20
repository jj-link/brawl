#pragma force_active on
typedef struct Obj {
    int pad0;
    int pad1;
    unsigned int flags;
} Obj;

extern "C" {
void fn_48_B984(Obj *p)
{
    p->flags &= ~0x400u;
}
}
