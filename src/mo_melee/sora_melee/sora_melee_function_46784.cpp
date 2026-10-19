#pragma force_active on
extern "C" void fn_27_46784(unsigned int* dst, const unsigned int* src) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
    *reinterpret_cast<float*>(dst + 6) = *reinterpret_cast<const float*>(src + 6);
    dst[7] = src[7];
}
