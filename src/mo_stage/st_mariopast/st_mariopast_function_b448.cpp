#pragma force_active on
struct FnObj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_48_B448(FnObj *obj)
{
    obj->flags |= 0x10;
}
}
