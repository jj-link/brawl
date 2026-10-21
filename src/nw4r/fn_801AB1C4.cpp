#pragma force_active on
extern "C" unsigned int fn_801AB1C4(int arg1, int (*arg2)(int, int), int arg3) {
    unsigned int result = (unsigned int)arg2(arg1, arg3) - 1;
    return (unsigned int)__cntlzw(result) >> 5;
}
