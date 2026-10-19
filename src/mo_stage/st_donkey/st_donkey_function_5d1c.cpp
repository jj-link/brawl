#pragma force_active on
typedef struct Obj
{
    int unk0;
    int unk4;
    unsigned int flags;
} Obj;

extern "C" int fn_50_5D1C(Obj *obj)
{
    return ((int)(obj->flags & 0x38000000) << 2) >> 30;
}
