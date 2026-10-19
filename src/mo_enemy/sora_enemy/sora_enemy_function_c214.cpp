#pragma force_active on
extern "C" void fn_41_C214(void* self, int index, float value) {
    float* values = *(float**)((char*)self + 0x14);
    values[index] = value;
}
