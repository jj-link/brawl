#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

extern "C" int fn_76_3F88(FnObj *obj)
{
    return (int)((obj->flags << 10) & 0xFC000000u) >> 27;
}
