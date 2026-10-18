#pragma force_active on
extern "C" void fn_100_993C(void* self, int index, float value) {
    float* array = *(float**)((char*)self + 0x14);
    array[index] = value;
}
