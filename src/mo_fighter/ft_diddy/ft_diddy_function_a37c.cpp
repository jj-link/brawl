#pragma force_active on
extern "C" void fn_115_A37C(void* self, unsigned int index, float value) {
    float* arr = *(float**)((char*)self + 0x14);
    arr[index] *= value;
}
