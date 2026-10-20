#pragma force_active on
extern "C" {
typedef struct {
    int field0;
    int field4;
    unsigned int flags;
} FnObj57;

void fn_57_AD1C(FnObj57 *obj)
{
    obj->flags &= ~0x02000000;
}
}
