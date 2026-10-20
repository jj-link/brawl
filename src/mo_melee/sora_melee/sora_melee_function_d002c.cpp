#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 hi : 7;
    u32 f : 7;
    u32 lo : 18;
} Obj;

extern "C" {
void fn_27_D002C(Obj *obj, u32 v)
{
    obj->f = v;
}
}
