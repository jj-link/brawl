#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
} FnState;

void fn_67_50A0(FnState *p, unsigned int v)
{
    p->b = v;
}
}
