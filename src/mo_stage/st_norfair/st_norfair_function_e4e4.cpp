#pragma force_active on
struct StObj {
    int field0;
    int field1;
    unsigned int flags;
};

extern "C" void fn_54_E4E4(StObj *obj)
{
    obj->flags |= 0x00080000;
}
