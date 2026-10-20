#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 a;
    u32 b;
    u32 hi : 6;
    u32 f : 6;
    u32 rest : 20;
};

extern "C" void fn_27_CFB64(Obj *obj, u32 val)
{
    obj->f = val;
}
