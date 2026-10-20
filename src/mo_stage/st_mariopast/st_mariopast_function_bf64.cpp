#pragma force_active on
struct FlagObj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_48_BF64(FlagObj *obj)
{
    obj->flags &= ~0x2000u;
}
}
