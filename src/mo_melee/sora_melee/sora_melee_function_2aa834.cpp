#pragma force_active on
struct Pair {
    unsigned int a;
    unsigned int b;
};

extern "C" void fn_27_2AA880(void*, int, Pair, int, int, int, int, int, int);

extern "C" void fn_27_2AA834(
    void* a, int b, Pair c, int d, int e, int f, int g, int h)
{
    fn_27_2AA880(a, b, c, d, e, e, f, g, h);
}
