#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 w0;
    u32 w1;
    u32 a : 10;
    u32 f : 5;
    u32 b : 17;
};

extern "C" void fn_27_19EF5C(Obj *obj, u32 val)
{
    obj->f = val;
}
