#pragma force_active on
typedef struct
{
    int pad[2];
    unsigned int flags;
} FnObj;

extern "C" int fn_70_9290(FnObj *obj)
{
    return (int)(((obj->flags >> 23) & 0x1F) << 27) >> 28;
}
