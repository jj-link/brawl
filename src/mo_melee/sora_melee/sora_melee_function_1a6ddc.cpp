#pragma force_active on
struct fn_27_s {
    unsigned int w0;
    unsigned int w1;
    unsigned int a : 20;
    unsigned int b : 10;
    unsigned int c : 2;
};

extern "C" void fn_27_1A6DDC(fn_27_s *p, unsigned int v)
{
    p->b = v;
}
