#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_112_AA5C(void* self, u32 index, float value)
{
    float* arr = *(float**)((char*)self + 0x14);
    arr[index] += value;
}
