#pragma force_active on
#pragma opt_propagation off

extern "C" void fn_80162B0C(float* dst, const float* src) {
    int offset = 0;
    __vec2x32float__ a = *(__vec2x32float__*)((const char*)src + offset);
    __vec2x32float__ b = *(const __vec2x32float__*)(src + 3);
    __vec2x32float__ c = *(const __vec2x32float__*)(src + 6);
    float x = src[2];
    float y = src[5];
    float z = src[8];

    *(__vec2x32float__*)((char*)dst + offset) = a;
    *(__vec2x32float__*)(dst + 4) = b;
    *(__vec2x32float__*)(dst + 8) = c;
    dst[2] = x;
    dst[6] = y;
    dst[10] = z;
}
