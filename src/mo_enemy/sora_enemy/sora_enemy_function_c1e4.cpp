#pragma force_active on
extern "C" void fn_41_C1E4(void* self, int idx, float v) {
    float* arr = *(float**)((char*)self + 0x14);
    arr[idx] -= v;
}
