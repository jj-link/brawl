#pragma force_active on
extern "C" void fn_8019AEB4(void* self, int index, float value) {
    float* array = *(float**)((char*)self + 0x20);
    array[index] = value;
}
