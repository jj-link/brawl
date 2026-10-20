#pragma force_active on
extern "C" {
struct S70 {
    unsigned int w0;
    unsigned int w1;
    unsigned int a : 2;
    unsigned int f : 2;
    unsigned int b : 28;
};
void fn_70_9078(struct S70 *p, unsigned int v)
{
    p->f = v;
}
}
