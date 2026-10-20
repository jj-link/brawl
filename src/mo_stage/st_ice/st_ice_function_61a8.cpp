#pragma force_active on
typedef struct Obj {
    unsigned int a;
    unsigned int b;
    struct {
        unsigned int hi : 4;
        unsigned int f : 4;
        unsigned int lo : 24;
    } c;
} Obj;

extern "C" void fn_62_61A8(Obj *p, unsigned int v)
{
    p->c.f = v;
}
