#pragma force_active on
struct fn27Obj {
    char pad[8];
    unsigned int f : 2;
    unsigned int g : 30;
};

extern "C" void fn_27_C5AC8(fn27Obj *obj, unsigned int val)
{
    obj->f = val;
}
