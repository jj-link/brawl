#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 6;
    unsigned int b : 3;
    unsigned int c : 23;
} FnState;

extern "C" void fn_51_DA04(FnState *s, unsigned int v)
{
    s->b = v;
}
