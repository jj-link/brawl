#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

extern "C" int fn_70_9004(FnObj *p)
{
    return (int)((p->flags << 4) & 0xE0000000u) >> 30;
}
