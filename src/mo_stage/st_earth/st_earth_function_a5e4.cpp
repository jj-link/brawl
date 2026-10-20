#pragma force_active on
extern "C" {
typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned int c : 4;
    unsigned int d : 2;
    unsigned int e : 26;
} S;

void fn_66_A5E4(S *p, unsigned int v)
{
    p->d = v;
}
}
