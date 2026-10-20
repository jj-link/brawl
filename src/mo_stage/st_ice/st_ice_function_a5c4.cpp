#pragma force_active on
typedef struct {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
} Bits;

typedef struct {
    unsigned int w0;
    unsigned int w1;
    Bits bits;
} Obj;

extern "C" {
void fn_62_A5C4(Obj *p, unsigned int v)
{
    p->bits.b = v;
}
}
