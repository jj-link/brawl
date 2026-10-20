#pragma force_active on
struct S {
    unsigned long a;
    unsigned long b;
    unsigned long pad : 8;
    unsigned long f : 4;
    unsigned long rest : 20;
};

extern "C" void fn_47_507C(struct S *obj, unsigned long v)
{
    obj->f = v;
}
