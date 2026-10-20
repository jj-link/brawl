#pragma force_active on
typedef struct {
    char pad[8];
    unsigned int a : 6;
    unsigned int f : 6;
    unsigned int b : 20;
} S;

extern "C" {
void fn_27_1CF914(S* s, unsigned int v)
{
    s->f = v;
}
}
