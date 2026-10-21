#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} Obj;

extern "C" int fn_76_3EF0(Obj *o)
{
    unsigned int v = o->flags;
    unsigned int r = (v << 10) | (v >> 22);
    return (int)(r & 0xFC000000) >> 27;
}
