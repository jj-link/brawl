#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

extern "C" {
int fn_50_6404(FnObj *obj)
{
    return (int)((obj->flags << 4) & 0xF8000000) >> 28;
}
}
