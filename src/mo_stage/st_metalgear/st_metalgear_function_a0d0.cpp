#pragma force_active on
typedef struct {
    unsigned int w0;
    unsigned int w1;
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
} FnState;

extern "C" void fn_71_A0D0(FnState *s, unsigned int v)
{
    s->b = v;
}
