#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

extern "C" void fn_77_3D6C(FnObj *obj)
{
    obj->flags &= ~0x00080000u;
}
