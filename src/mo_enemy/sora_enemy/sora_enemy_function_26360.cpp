#pragma force_active on
extern "C" unsigned int fn_27_14D530(unsigned int);
extern "C" unsigned int fn_41_23BD4(unsigned int, unsigned int);

extern "C" unsigned int fn_41_26360(unsigned int a, unsigned int b) {
    if (b <= 3) {
        return fn_27_14D530(fn_41_23BD4(a, b));
    }
    return 0;
}
