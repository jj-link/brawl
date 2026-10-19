#pragma force_active on
struct Pair { unsigned int lo; unsigned int hi; };

struct Big { unsigned int a; unsigned int b; Pair pair; };

extern "C" Pair fn_120_BE94(const Big* arg0)
{
    return arg0->pair;
}
