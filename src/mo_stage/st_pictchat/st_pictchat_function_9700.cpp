#pragma force_active on
union Value {
    struct {
        unsigned int high, low;
    } words;
    unsigned long long value;
};

extern "C" unsigned long long fn_73_9700() {
    Value result = { 0, 0 };
    return result.value;
}
