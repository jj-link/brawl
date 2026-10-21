#pragma force_active on
extern "C" void fn_801C606C(void *src, void *dst) {
    float* dst_f = (float*)((char*)dst + 0xC);
    dst_f[0] = *(float*)((char*)src + 0xB8);
    dst_f[1] = *(float*)((char*)src + 0xBC);
    dst_f[2] = *(float*)((char*)src + 0xC0);
    *(int*)dst = *(int*)((char*)src + 0xB4);
}
