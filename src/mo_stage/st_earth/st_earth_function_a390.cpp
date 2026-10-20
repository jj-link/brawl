#pragma force_active on
typedef struct FnObj {
    int pad[2];
    unsigned int flags;
} FnObj;

extern "C" void fn_66_A390(FnObj *obj)
{
    obj->flags &= ~0x02000000;
}
