#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int hi:4;
    unsigned int f:2;
    unsigned int lo:26;
} S;

extern "C" void fn_49_6C00(S *s, unsigned int v)
{
    s->f = v;
}
