#pragma force_active on
extern "C" void fn_104_AA88(void* work, int index, float value) {
    float* floats = *(float**)((char*)work + 0x14);
    floats[index] = value;
}
