#pragma force_active on
extern "C" void fn_100_9924(void* obj, int index, float value) {
    float* arr = *(float**)((char*)obj + 0x14);
    arr[index] += value;
}
