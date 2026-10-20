#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
} S;

extern "C" void fn_51_6610(S *s, unsigned int v)
{
    s->b = v;
}
