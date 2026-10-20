#pragma force_active on
extern "C" float fn_61_E680(const char* self, unsigned int index) {
    float* arr = *(float**)(self + 0x5ac);
    return arr[index];
}
