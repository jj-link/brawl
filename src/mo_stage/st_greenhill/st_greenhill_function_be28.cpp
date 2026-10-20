#pragma force_active on
extern "C" {
typedef struct Obj {
    int pad0;
    int pad1;
    unsigned int flags;
} Obj;

int fn_72_BE28(Obj *p)
{
    return (int)((p->flags >> 25 & 0xF) << 28) >> 29;
}
}
