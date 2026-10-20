#pragma force_active on
struct Obj {
    int pad0;
    int pad1;
    unsigned int flags;
};

extern "C" {
void fn_76_401C(struct Obj *p)
{
    p->flags |= 0x80000;
}
}
