#pragma force_active on
extern "C" void fn_100_98F4(void* self, int index, float scale) {
    float* arr = *(float**)((char*)self + 0x14);
    arr[index] *= scale;
}
