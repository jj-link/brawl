#pragma force_active on
struct Fn76Obj {
    unsigned int pad0[2];
    unsigned int hi : 5;
    unsigned int field : 5;
    unsigned int lo : 22;
};

extern "C" void fn_76_3E9C(Fn76Obj *obj, unsigned int val)
{
    obj->field = val;
}
