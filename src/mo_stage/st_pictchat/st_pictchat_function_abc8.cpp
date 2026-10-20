#pragma force_active on
typedef struct Obj {
    unsigned int w0;
    unsigned int w1;
    struct {
        unsigned int a : 6;
        unsigned int b : 3;
        unsigned int c : 23;
    } w2;
} Obj;

extern "C" {
void fn_73_ABC8(Obj *p, unsigned int v)
{
    p->w2.b = v;
}
}
