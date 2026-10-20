#pragma force_active on
struct FlagObj {
    int a;
    int b;
    unsigned int flags;
};

extern "C" void fn_48_B800(struct FlagObj *obj)
{
    obj->flags |= 0x400;
}
