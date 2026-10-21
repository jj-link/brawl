#pragma force_active on
extern "C" int fn_8004AD5C(void *arg0) {
    int *r4 = *(int **)((char *)arg0 + 0x18);
    int result = 0;
    if (r4) {
        unsigned int r0 = __cntlzw((unsigned int)*r4 - 1);
        result = r0 >> 5;
    }
    return result;
}
