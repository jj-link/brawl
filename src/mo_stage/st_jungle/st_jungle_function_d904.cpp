#pragma force_active on
extern "C" {
typedef struct Obj {
    int pad[2];
    unsigned int flags;
} Obj;

int fn_51_D904(Obj *p)
{
    return (int)((p->flags << 6) & 0xF0000000) >> 29;
}
}
