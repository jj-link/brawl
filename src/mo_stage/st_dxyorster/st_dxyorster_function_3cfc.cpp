#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} Obj;

extern "C" int fn_76_3CFC(Obj *o)
{
    unsigned int x = o->flags;
    return (int)(((x >> 21) & 0x3F) << 26) >> 27;
}
