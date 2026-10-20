#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

#ifdef __cplusplus
extern "C"
#endif
void fn_51_67DC(FnObj *p)
{
    p->flags &= 0xFFF7FFFF;
}
