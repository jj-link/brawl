#pragma force_active on
struct FnObj49 {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" void fn_49_6B94(FnObj49 *obj)
{
    obj->flags |= 0x02000000;
}
