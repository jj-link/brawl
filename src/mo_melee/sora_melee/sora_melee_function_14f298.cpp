#pragma force_active on
struct SoFlagsObj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" void fn_27_14F298(SoFlagsObj *obj)
{
    obj->flags |= 0x400;
}
