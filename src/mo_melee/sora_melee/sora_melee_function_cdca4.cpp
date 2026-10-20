#pragma force_active on
typedef struct Obj {
    int pad[2];
    unsigned int flags;
} Obj;

extern "C" {
int fn_27_CDCA4(Obj *p)
{
    unsigned int x = p->flags;
    unsigned int r = (x << 10) | (x >> 22);
    return (int)(r & 0xFC000000u) >> 27;
}
}
