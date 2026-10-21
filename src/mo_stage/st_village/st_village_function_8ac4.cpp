#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} Obj;

extern "C" int fn_70_8AC4(Obj *p)
{
    return (int)((p->flags << 2) & 0xE0000000u) >> 30;
}
