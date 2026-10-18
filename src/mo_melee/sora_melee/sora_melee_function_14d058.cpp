#pragma force_active on
extern "C" void fn_27_14D058(char *p, int idx, int val) {
    p += idx * 4;
    *(int *)(p + 0x118) += val;
}
