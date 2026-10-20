#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    unsigned int a : 6;
    unsigned int f : 6;
    unsigned int b : 20;
} S;

void fn_79_599C(S *s, unsigned int v)
{
    s->f = v;
}
}
