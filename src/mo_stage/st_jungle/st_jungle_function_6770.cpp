#pragma force_active on
typedef struct {
    int a;
    int b;
    unsigned int hi : 4;
    unsigned int f : 2;
    unsigned int lo : 26;
} S;

extern "C" void fn_51_6770(S *p, unsigned int v)
{
    p->f = v;
}
