#pragma force_active on
extern "C" unsigned int fn_41_26054(unsigned int, unsigned int);
extern "C" unsigned int fn_27_14D530(unsigned int);

extern "C" unsigned int fn_41_263C8(unsigned int a, unsigned int b, unsigned int c,
                                    unsigned int d) {
    if (b <= 3) {
        return fn_27_14D530(fn_41_26054(a, b));
    }
    return 0;
}
