#pragma force_active on
extern "C" {
typedef struct
{
    int pad[2];
    unsigned int flags;
} FnObj;

int fn_76_4050(FnObj *obj)
{
    return (int)((obj->flags << 8) & 0xF8000000u) >> 28;
}
}
