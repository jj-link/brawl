#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

#ifdef __cplusplus
extern "C"
#endif
void fn_48_3EDC(FnObj *obj)
{
    obj->flags |= 0x80000;
}
