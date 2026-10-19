#pragma force_active on
extern "C" {
unsigned long long fn_96_23DB0(void);
}

extern "C" unsigned long long fn_96_23DB0(void)
{
    union Pair {
        unsigned long long packed;
        struct { unsigned int first, second; } words;
    };
    Pair result;
    result.words.first = 0;
    result.words.second = 0;
    return result.packed;
}
