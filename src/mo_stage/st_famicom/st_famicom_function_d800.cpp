#pragma force_active on
typedef unsigned long u32;

typedef struct Obj
{
    char pad[8];
    u32 a : 8;
    u32 b : 4;
    u32 c : 20;
} Obj;

extern "C" {
void fn_68_D800(Obj *obj, u32 v)
{
    obj->b = v;
}
}
