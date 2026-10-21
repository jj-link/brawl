#pragma force_active on
extern "C" void fn_72_C004(void *obj, unsigned int val)
{
    struct F {
        unsigned int a : 6;
        unsigned int b : 3;
        unsigned int c : 23;
    };
    F *p = (F *)((char *)obj + 8);
    p->b = val;
}
