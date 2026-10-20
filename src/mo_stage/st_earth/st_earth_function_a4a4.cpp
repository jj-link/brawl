#pragma force_active on
struct Obj {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int f : 2;
    unsigned int b : 28;
};

extern "C" void fn_66_A4A4(struct Obj *o, unsigned int v)
{
    o->f = v;
}
