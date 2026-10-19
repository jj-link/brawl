#pragma force_active on
extern "C" {
typedef struct {
    char pad[0x1c];
    unsigned long flags;
} FlagObj;

void fn_90_29D4(FlagObj *obj, int enable)
{
    if (enable) {
        obj->flags |= 0x4;
    } else {
        obj->flags &= ~0x4;
    }
}
}
