#pragma force_active on
typedef struct {
    int field0;
    int field4;
    unsigned int flags;
} St_Obj;

#ifdef __cplusplus
extern "C" {
#endif

void fn_47_4BD0(St_Obj *obj)
{
    obj->flags &= ~0x02000000;
}

#ifdef __cplusplus
}
#endif
