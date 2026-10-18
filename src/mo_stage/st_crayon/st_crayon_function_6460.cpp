#pragma force_active on
typedef struct Obj {
    int pad0;
    int pad1;
    unsigned int flags;
} Obj;

extern "C" unsigned int fn_56_6460(Obj *obj)
{
    return (obj->flags >> 25) & 1;
}
