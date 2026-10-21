#pragma force_active on

extern const float lbl_41_rodata_18;
extern "C" void fn_41_2354(float* r3, float f1, float f2);
extern "C" float fn_41_5828(const void* a, const void* b);

extern "C" int fn_41_58C8(void* a, int* arr, unsigned count, const void* p) {
    int result = -1;
    float threshold = lbl_41_rodata_18;
    float local[2];
    for (unsigned i = 0; i < count; i++) {
        int ptr = arr[i];
        if (ptr == 0) continue;
        fn_41_2354(local, *(float*)ptr, *(float*)(ptr + 4));
        float v = fn_41_5828(p, local);
        if (v > threshold) {
            result = i;
            threshold = v;
        }
    }
    return result;
}
