#pragma force_active on
struct FlagObj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};

extern "C" void fn_27_385BFC(FlagObj *obj)
{
    obj->flags |= 0x2;
}
