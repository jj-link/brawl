#pragma force_active on
struct Inner
{
    char pad[0x4a0];
    float m;
};

struct Outer
{
    Inner *p;
};

extern "C" void fn_27_111D8C(Outer *o, float f)
{
    o->p->m = f;
}
