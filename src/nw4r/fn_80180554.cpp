#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_80180554(u32* dst, const u32* a, const u32* b, float f) {
    dst[0] = a[0];
    dst[1] = a[1];
    dst[2] = a[2];
    dst[3] = b[0];
    dst[4] = b[1];
    dst[5] = b[2];
    *reinterpret_cast<float*>(dst + 6) = f;
}
