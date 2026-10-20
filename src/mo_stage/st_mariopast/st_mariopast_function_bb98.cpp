#pragma force_active on
struct Obj {
    int pad[2];
    unsigned int a : 6;
    unsigned int b : 6;
    unsigned int c : 20;
};

extern "C" void fn_48_BB98(struct Obj *obj, unsigned int val)
{
    obj->b = val;
}
