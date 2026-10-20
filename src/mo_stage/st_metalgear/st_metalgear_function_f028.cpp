#pragma force_active on
extern "C" float fn_71_F028(char* self, unsigned int index) {
    float* arr = *(float**)(self + 0x51c);
    return arr[index];
}
