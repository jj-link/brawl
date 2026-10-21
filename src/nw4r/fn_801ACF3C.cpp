#pragma force_active on
extern "C" {
typedef struct {
    char pad[0xec];
    unsigned int field_ec;
    unsigned int flags;
} Obj;

void fn_801ACF3C(Obj *obj, int enable, unsigned int value)
{
    if (enable) {
        obj->field_ec = value;
        obj->flags |= 0x1;
    } else {
        obj->flags &= ~0x1u;
    }
}
}
