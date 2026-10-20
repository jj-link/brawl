#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

extern "C" int fn_67_522C(FnObj *obj)
{
    return (int)((obj->flags << 4) & 0xF8000000u) >> 28;
}
