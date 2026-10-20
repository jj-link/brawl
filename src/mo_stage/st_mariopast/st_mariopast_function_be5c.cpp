#pragma force_active on
extern "C" {
int fn_48_BE5C(void *ptr) {
    int val = *(int *)((char *)ptr + 8);
    return val >> 26;
}
}
