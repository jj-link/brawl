#pragma force_active on
typedef struct {
    unsigned int p[2];
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
} FnStruct;

extern "C" {
void fn_72_4F54(FnStruct *s, unsigned int v)
{
    s->b = v;
}
}
