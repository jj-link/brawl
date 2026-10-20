#pragma force_active on
typedef struct Obj {
    int field0;
    int field1;
    unsigned int flags;
} Obj;

extern "C" void fn_67_5034(Obj *obj)
{
    obj->flags |= 0x02000000;
}
