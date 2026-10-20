#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
} Obj;

extern "C" void fn_47_4CF4(Obj *p, unsigned int v)
{
    p->b = v;
}
