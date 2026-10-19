#pragma force_active on
extern "C" unsigned long long fn_100_134B8() {
    struct Pair {
        unsigned int hi;
        unsigned int lo;
    };
    Pair p;
    p.hi = 0;
    p.lo = 0;
    return *(unsigned long long*)&p;
}
