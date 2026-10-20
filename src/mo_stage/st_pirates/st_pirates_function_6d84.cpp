#pragma force_active on
extern "C" float fn_52_6D84(char* self, unsigned int index) {
    float* arr = *(float**)(self + 0x51c);
    return arr[index];
}
