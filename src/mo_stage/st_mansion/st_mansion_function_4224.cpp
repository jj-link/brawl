#pragma force_active on
typedef struct {
    int a;
    int b;
    unsigned int flags;
} FnObj;

extern "C" int fn_47_4224(FnObj *obj)
{
    unsigned int x = obj->flags;
    unsigned int r = ((x << 2) | (x >> 30)) & 0xE0000000u;
    return ((int)r) >> 30;
}
