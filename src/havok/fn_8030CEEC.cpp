#pragma force_active on
struct Pair { unsigned short key; unsigned short val; };
struct Flag { signed char value; Flag(bool b) : value(b) {} operator bool() const { return value != 0; } };
struct Comp {
    Flag operator()(const Pair& a, const Pair& b) const { return (int)a.key - (int)b.key < 0; }
};
extern "C" void fn_8030CEEC(Pair* arr, int lo, int hi, Comp comp) {
top:
    Pair pivot __attribute__((aligned(16)));
    pivot = arr[(unsigned int)(lo + hi) >> 1];
    int j = hi;
    int i = lo;
    do {
        while (comp(arr[i], pivot)) { ++i; }
        while (comp(pivot, arr[j])) { --j; }
        if (j >= i) {
            if (j != i) {
                Pair temp __attribute__((aligned(16)));
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
            --j;
            ++i;
        }
    } while (i <= j);
    if (lo < j) {
        fn_8030CEEC(arr, lo, j, comp);
    }
    if (i < hi) { lo = i; goto top; }
}
