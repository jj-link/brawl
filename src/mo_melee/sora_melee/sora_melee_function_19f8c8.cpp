#pragma force_active on
struct Obj {
    unsigned long a;
    unsigned long b;
    unsigned long pad : 12;
    unsigned long value : 1;
};

extern "C" unsigned long fn_27_19F8C8(const Obj *p)
{
    return p->value;
}
