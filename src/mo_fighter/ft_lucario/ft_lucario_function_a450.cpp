#pragma force_active on
extern "C" void fn_118_A450(void* object, int index, float scale) {
    float* arr = *(float**)((char*)object + 0x14);
    arr[index] *= scale;
}
