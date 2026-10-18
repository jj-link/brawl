#pragma force_active on
typedef struct {
    int a;
    int b;
} Pair;

extern "C" void fn_96_1F8A4(Pair *dst, const Pair *src)
{
    *dst = *src;
}
