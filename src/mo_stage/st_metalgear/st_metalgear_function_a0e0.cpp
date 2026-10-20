#pragma force_active on
typedef struct {
    unsigned int w0;
    unsigned int w1;
    unsigned int mode : 2;
    unsigned int rest : 30;
} FnState;

extern "C" void fn_71_A0E0(FnState *s, unsigned int v)
{
    s->mode = v;
}
