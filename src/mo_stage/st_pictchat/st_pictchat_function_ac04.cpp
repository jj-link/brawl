#pragma force_active on
extern "C" void fn_73_AC04(unsigned int *p, unsigned int v)
{
    struct F {
        unsigned int a : 2;
        unsigned int b : 2;
        unsigned int rest : 28;
    };
    ((F *)p)[2].b = v;
}
