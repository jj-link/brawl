#pragma force_active on
extern "C" void fn_27_C77B0(unsigned int* dst, const unsigned int* src) {
    if (dst == src) {
        return;
    }

    if (dst + 1 != src + 1) {
        dst[1] = src[1];
    }

    dst[2] = src[2];
    dst[3] = src[3];

    if (dst[2] == 0) {
        dst[3] = 0;
    }
}
