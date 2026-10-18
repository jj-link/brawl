#pragma force_active on
struct Pair {
    unsigned int a;
    unsigned int b;
};

extern "C" unsigned long long fn_68_5A58() {
    Pair p = {0, 0};
    return *reinterpret_cast<unsigned long long*>(&p);
}
