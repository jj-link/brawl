#pragma force_active on
typedef struct Obj {
    int pad0;
    int pad4;
    unsigned int flags;
} Obj;

extern "C" void fn_51_65B8(Obj *obj)
{
    obj->flags |= 0x02000000;
}
