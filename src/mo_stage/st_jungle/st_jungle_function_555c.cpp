#pragma force_active on
union Value {
    struct {
        unsigned int hi;
        unsigned int lo;
    } words;
    unsigned long long value;
};

extern "C" unsigned long long fn_51_555C() {
    Value result;
    result.words.hi = 0;
    result.words.lo = 0;
    return result.value;
}
