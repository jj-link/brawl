#pragma force_active on
struct Obj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_295894(Obj* p)
{
    p->flags |= 0x10000;
}
}
