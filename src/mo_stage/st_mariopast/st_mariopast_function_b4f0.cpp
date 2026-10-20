#pragma force_active on
struct Obj {
    unsigned int w0;
    unsigned int w1;
    unsigned int hi : 9;
    unsigned int f : 9;
    unsigned int lo : 14;
};

extern "C" void fn_48_B4F0(Obj *obj, unsigned int v)
{
    obj->f = v;
}
