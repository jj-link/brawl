#pragma force_active on
struct FnObj57 {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" void fn_57_AE6C(FnObj57 *obj)
{
    obj->flags |= 0x00080000;
}
