#pragma force_active on
typedef unsigned int u32;

extern const float lbl_41_rodata_BE0;

extern "C" {
float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* self, u32 a, u32 b);
void* getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(void* self, u32 a, u32 b);

float fn_41_11B48(void* self) {
    float val = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(*(void**)((char*)self + 0x3c), 0x1100000C, 0);
    float* f = (float*)getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(*(void**)((char*)self + 0x3c), 0x10000 - 0x57E3, 0);
    float result = f[0];
    float v = f[1];
    if (lbl_41_rodata_BE0 != v) {
        result += v * val;
    }
    return result;
}
}
