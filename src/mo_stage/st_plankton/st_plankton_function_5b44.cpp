#pragma force_active on
union Value {
    struct {
        unsigned int a, b;
    } words;
    unsigned long long whole;
};

extern "C" unsigned long long fn_74_5B44()
{
    Value value;
    value.words.a = 0;
    value.words.b = 0;
    return value.whole;
}
