#pragma force_active on
typedef struct Obj {
    int pad[2];
    unsigned int flags;
} Obj;

extern "C" void fn_48_B684(Obj *obj)
{
    obj->flags |= 0x10;
}
