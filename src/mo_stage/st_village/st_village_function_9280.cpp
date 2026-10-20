#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int hi : 4;
    unsigned int rest : 28;
} S70;

extern "C" {
void fn_70_9280(S70 *p, unsigned int v)
{
    p->hi = v;
}
}
