#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int top : 2;
    unsigned int rest : 30;
} S;

extern "C" void fn_67_5178(S *s, unsigned int v)
{
    s->top = v;
}
