#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int a : 6;
    unsigned int b : 6;
    unsigned int c : 20;
} S;

extern "C" void fn_79_5760(S *s, unsigned int v)
{
    s->b = v;
}
