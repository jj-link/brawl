#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int w;
} Obj;

extern "C" int fn_57_ADD8(Obj *p)
{
    return (int)(((p->w >> 22) & 0xF) << 28) >> 29;
}
