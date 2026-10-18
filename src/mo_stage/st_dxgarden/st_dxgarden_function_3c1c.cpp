#pragma force_active on
typedef struct {
    int a;
    int b;
    unsigned int flags;
} FnObj;

extern "C" {
unsigned int fn_77_3C1C(FnObj *obj)
{
    return (obj->flags >> 25) & 1;
}
}
