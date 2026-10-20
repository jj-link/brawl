#pragma force_active on
struct Obj {
    unsigned int pad[2];
    unsigned int a : 12;
    unsigned int f : 6;
    unsigned int b : 14;
};

extern "C" void fn_48_BC24(struct Obj *obj, unsigned int v)
{
    obj->f = v;
}
