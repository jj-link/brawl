#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 x0;
    u32 x1;
    u32 a : 20;
    u32 f : 10;
    u32 b : 2;
};

extern "C" {
void fn_27_927D4(Obj *obj, u32 val)
{
    obj->f = val;
}
}
