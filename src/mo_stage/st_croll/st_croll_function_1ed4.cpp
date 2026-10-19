#pragma force_active on
struct Triple
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

extern "C" void fn_90_1ED4(Triple* dst, const Triple* src)
{
    *dst = *src;
}
