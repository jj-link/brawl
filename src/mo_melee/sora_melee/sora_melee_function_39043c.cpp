#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int a : 8;
    unsigned int b : 4;
    unsigned int c : 20;
} FieldHolder;

extern "C" void fn_27_39043C(FieldHolder *p, unsigned int v)
{
    p->b = v;
}
