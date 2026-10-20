#pragma force_active on
typedef unsigned int u32;

typedef struct {
    char pad[8];
    u32 flags;
} FnObj;

extern "C" int fn_49_606C(FnObj *obj)
{
    return (int)((obj->flags >> 27) << 29) >> 30;
}
