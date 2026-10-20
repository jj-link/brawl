#pragma force_active on
extern "C" void fn_72_4FE0(unsigned int *p, unsigned int v)
{
    struct F {
        unsigned int a : 4;
        unsigned int b : 2;
        unsigned int c : 26;
    };
    ((F *)(p + 2))->b = v;
}
