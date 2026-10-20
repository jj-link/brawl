#pragma force_active on
extern "C" {
typedef struct {
    unsigned int hi : 2;
    unsigned int rest : 30;
} Hdr;

typedef struct {
    unsigned int w0;
    unsigned int w1;
    Hdr h;
} Obj;

void fn_71_9F5C(Obj *p, unsigned int v)
{
    p->h.hi = v;
}
}
