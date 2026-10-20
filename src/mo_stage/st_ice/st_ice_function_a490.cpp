#pragma force_active on
struct FnObj {
    int field0;
    int field1;
    unsigned int flags;
};

extern "C" {
void fn_62_A490(FnObj *obj)
{
    obj->flags |= 0x02000000;
}
}
