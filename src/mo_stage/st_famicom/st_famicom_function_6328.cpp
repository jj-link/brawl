#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

extern "C" {
int fn_68_6328(FnObj *obj)
{
    return ((int)((obj->flags << 2) & 0xE0000000)) >> 30;
}
}
