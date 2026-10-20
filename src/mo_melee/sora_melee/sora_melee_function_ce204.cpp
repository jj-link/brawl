#pragma force_active on
struct FlagObj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_CE204(FlagObj *obj)
{
    obj->flags |= 0x80;
}
}
