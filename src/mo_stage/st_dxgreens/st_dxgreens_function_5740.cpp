#pragma force_active on
struct Sub08
{
    unsigned int w0;
    unsigned int w1;
    unsigned int top : 6;
    unsigned int rest : 26;
};

extern "C" {
void fn_79_5740(struct Sub08 *p, unsigned int v)
{
    p->top = v;
}
}
