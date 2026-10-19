#pragma force_active on
extern "C" unsigned long long fn_108_10D08(void) {
    union Pair {
        struct {
            unsigned int first;
            unsigned int second;
        } words;
        unsigned long long packed;
    } result;

    result.words.first = 0;
    result.words.second = 0;
    return result.packed;
}
