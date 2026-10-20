#pragma force_active on
struct FnObj48B738 {
    int field0;
    int field4;
    unsigned int flags;
};

extern "C" void fn_48_B738(FnObj48B738 *obj)
{
    obj->flags |= 0x400;
}
