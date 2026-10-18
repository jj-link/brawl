#pragma force_active on
extern "C" int fn_71_2358(void* self, int, int* out1, int* out2) {
    unsigned char* p = (unsigned char*)self;
    if (p[0x2e5] == 0 && p[0x2e6] == 0)
        return 0;
    int value = *(int*)(p + 0x2e0);
    if (value == 0 || (p[0x2e6] != 0 && value == 1)) {
        *out1 = 6;
        *out2 = 3;
        return 1;
    }
    return 0;
}
