#pragma force_active on
typedef struct {
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
} S;

extern "C" {
void fn_79_5A50(S *p, unsigned int v)
{
    p[2].b = v;
}
}
