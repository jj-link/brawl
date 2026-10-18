#pragma force_active on
union Value {
    struct {
        unsigned int hi;
        unsigned int lo;
    } words;
    unsigned long long value;
};

extern "C" unsigned long long fn_61_99BC() {
    Value v;
    v.words.hi = 0;
    v.words.lo = 0;
    return v.value;
}
