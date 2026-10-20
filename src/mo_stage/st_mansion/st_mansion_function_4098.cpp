#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} Obj;

extern "C" int fn_47_4098(Obj *o)
{
    return (int)((o->flags << 2) & 0xE0000000u) >> 30;
}
