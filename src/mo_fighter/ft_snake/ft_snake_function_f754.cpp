#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_122_F754(char* self, u32 index, float value) {
    float* arr = *(float**)(self + 0x14);
    arr[index] *= value;
}
