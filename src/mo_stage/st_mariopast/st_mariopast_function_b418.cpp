#pragma force_active on
typedef struct {
    int pad0;
    unsigned int pad1;
    unsigned int flags;
} Obj;

extern "C" int fn_48_B418(Obj *obj)
{
    return (int)((obj->flags << 9) & 0xFFC00000u) >> 23;
}
