#pragma force_active on
struct FnObj27 {
    int unk0;
    int unk4;
    unsigned int flags8;
};

extern "C" void fn_27_CA700(FnObj27 *obj)
{
    obj->flags8 |= 0x10000;
}
