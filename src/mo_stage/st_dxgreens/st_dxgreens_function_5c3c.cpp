#pragma force_active on
struct FieldWord {
    unsigned int a : 8;
    unsigned int b : 4;
    unsigned int c : 20;
};

struct Obj {
    unsigned int pad[2];
    FieldWord f;
};

extern "C" void fn_79_5C3C(Obj *p, unsigned int v)
{
    p->f.b = v;
}
