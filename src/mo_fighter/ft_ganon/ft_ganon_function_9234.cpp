#pragma force_active on
extern "C" const float lbl_109_rodata_8;

extern "C" void fn_109_9234(void* object, float value, unsigned int index) {
    if (lbl_109_rodata_8 != value) {
        float* works = *(float**)((char*)object + 0x14);
        works[index] /= value;
    }
}
