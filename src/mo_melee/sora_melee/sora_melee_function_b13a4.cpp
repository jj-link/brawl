#pragma force_active on
struct Obj {
    unsigned int a;
    unsigned int b;
    unsigned int hi : 10;
    unsigned int f : 5;
    unsigned int lo : 17;
};

extern "C" {
void fn_27_B13A4(Obj* p, unsigned int v)
{
    p->f = v;
}
}
