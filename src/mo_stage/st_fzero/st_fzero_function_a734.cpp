#pragma force_active on
struct FzeroObj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" void fn_61_A734(FzeroObj *obj)
{
    obj->flags &= 0xFDFFFFFF;
}
