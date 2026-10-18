#pragma force_active on
extern "C" void fn_98_A090(float** self, int index, float scale) {
    float* arr = *(float**)((char*)self + 0x14);
    arr[index] *= scale;
}
