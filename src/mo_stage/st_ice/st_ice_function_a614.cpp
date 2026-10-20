#pragma force_active on
typedef struct StObj {
    int field0;
    int field1;
    unsigned int flags;
} StObj;

extern "C" void fn_62_A614(StObj *obj)
{
    obj->flags &= 0xFDFFFFFF;
}
