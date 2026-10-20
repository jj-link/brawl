#pragma force_active on
struct FnObj48 {
    int pad0;
    int pad1;
    unsigned int flags;
};

extern "C" {
void fn_48_BC74(FnObj48 *obj)
{
    obj->flags &= ~0x2000;
}
}
