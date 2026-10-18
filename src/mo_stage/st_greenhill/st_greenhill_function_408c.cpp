#pragma force_active on
extern "C" unsigned long long fn_72_408C()
{
    union {
        struct {
            unsigned int hi;
            unsigned int lo;
        } words;
        unsigned long long value;
    } result;

    result.words.hi = 0;
    result.words.lo = 0;
    return result.value;
}
