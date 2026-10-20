#pragma force_active on
typedef struct FnObj {
    int pad0;
    int pad1;
    unsigned int flags;
} FnObj;

#ifdef __cplusplus
extern "C"
#endif
void fn_71_9ED4(FnObj *obj)
{
    obj->flags |= 0x02000000;
}
