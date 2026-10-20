#pragma force_active on
extern "C" int fn_27_1CFC34(const void *obj) {
    int w = *(const int *)((const char *)obj + 8);
    return (w >> 16) & 1;
}