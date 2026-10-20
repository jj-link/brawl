#pragma force_active on
extern "C" {
typedef struct {
    int a;
    int b;
    unsigned int u0 : 4;
    signed int f : 4;
    unsigned int u1 : 24;
} FieldWord;

int fn_76_3FEC(FieldWord *p)
{
    return p->f;
}
}
