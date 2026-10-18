#pragma force_active on
extern "C" void fn_117_A760(void* self, int index, float scale) {
    float* arr = *(float**)((char*)self + 0x14);
    arr[index] *= scale;
}
