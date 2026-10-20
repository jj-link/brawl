#pragma force_active on
typedef struct Obj68
{
    int unk0;
    int unk4;
    unsigned int flags;
} Obj68;

extern "C" {
void fn_68_6580(Obj68 *obj)
{
    obj->flags |= 0x00080000;
}
}
