#pragma force_active on
extern "C" void fn_800445FC(unsigned int* p, unsigned int n) {
    *p = n;
    unsigned int count = (n + 1) >> 5;
    for (int i = 0; i < count; ++i) {
        *++p = 0;
    }
}