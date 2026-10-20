#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int c : 24;
} S;

extern "C" void fn_51_67AC(S *s, unsigned int v)
{
    s->b = v;
}
