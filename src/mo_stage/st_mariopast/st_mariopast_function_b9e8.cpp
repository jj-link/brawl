#pragma force_active on
extern "C" {
typedef struct {
    unsigned int pad[2];
    unsigned int hi : 6;
    unsigned int rest : 26;
} FnState;

void fn_48_B9E8(FnState *p, unsigned int v)
{
    p->hi = v;
}
}
