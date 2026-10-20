#pragma force_active on
typedef unsigned int u32;

typedef struct Obj {
    char pad[8];
    u32 hi : 8;
    u32 f : 4;
    u32 lo : 20;
} Obj;

extern "C" {
void fn_27_CBBD0(Obj *obj, u32 val)
{
    obj->f = val;
}
}
