#pragma force_active on
extern "C" void fn_48_B9CC(unsigned int *p, unsigned int v)
{
    struct F { unsigned int a : 14; unsigned int b : 7; unsigned int c : 11; };
    ((F *)(p + 2))->b = v;
}
