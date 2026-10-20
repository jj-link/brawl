#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
} FieldHolder;

extern "C" void fn_70_91D8(FieldHolder *p, unsigned int v)
{
    p->b = v;
}
