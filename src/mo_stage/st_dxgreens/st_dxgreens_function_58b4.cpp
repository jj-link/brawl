#pragma force_active on
typedef struct {
    unsigned int pad0 : 12;
    unsigned int field : 6;
    unsigned int pad1 : 14;
} Bits;

typedef struct {
    unsigned int w0;
    unsigned int w1;
    Bits bits;
} Obj;

extern "C" void fn_79_58B4(Obj *p, unsigned int v)
{
    p->bits.field = v;
}
