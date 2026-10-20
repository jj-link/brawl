#pragma force_active on
extern "C" {
typedef struct FnObj {
    int pad0;
    int pad1;
    unsigned int flags;
} FnObj;

void fn_74_6984(FnObj *obj)
{
    obj->flags |= 0x02000000;
}
}
