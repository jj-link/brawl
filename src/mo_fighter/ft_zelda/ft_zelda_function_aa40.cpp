#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_104_AA40(void* self, u32 index, float scale) {
    float* arr = *(float**)((char*)self + 0x14);
    arr[index] *= scale;
}
