#pragma force_active on
extern "C" void fn_76_3E60(unsigned int *p, unsigned int v)
{
    struct F { unsigned int a : 10; unsigned int f : 5; unsigned int b : 17; };
    ((F *)(p + 2))->f = v;
}
