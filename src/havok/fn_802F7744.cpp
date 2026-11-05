#pragma force_active on
#pragma use_lmw_stmw on
struct Result { signed char value; operator bool() const { return value != 0; } };
struct Value {
    unsigned char flag;
    int words[4];
    Value() : flag(0) {}
};
typedef Result (*Compare)(Value*, Value*);
extern "C" void fn_802F7744(Value* data, int left, int right, Compare compare) {
    Value pivot __attribute__((aligned(16)));
loop:
    {
        int j = right;
        int i = left;
        pivot = data[(left + right) >> 1];
        do {
            while (compare(&data[i], &pivot)) ++i;
            while (compare(&pivot, &data[j])) --j;
            if (j >= i) {
                if (j != i) {
                    Value& high = data[j];
                    Value temp __attribute__((aligned(16)));
                    temp = high;
                    high = data[i];
                    data[i] = temp;
                }
                --j;
                ++i;
            }
        } while (i <= j);
        if (left < j) fn_802F7744(data, left, j, compare);
        if (i < right) {
            left = i;
            goto loop;
        }
    }
}
