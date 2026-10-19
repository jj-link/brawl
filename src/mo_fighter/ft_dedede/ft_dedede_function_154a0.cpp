#pragma force_active on
union Value {
    struct {
        unsigned int high;
        unsigned int low;
    } words;
    unsigned long long value;
};

extern "C" unsigned long long fn_117_154A0() {
    Value result;
    result.words.high = 0;
    result.words.low = 0;
    return result.value;
}
