#pragma force_active on
extern "C" void fn_105_DD54(void* work, unsigned int index, float value) {
    float* arr = *(float**)((char*)work + 0x14);
    arr[index] += value;
}
