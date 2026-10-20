#pragma force_active on
extern "C" float fn_54_100A0(void* self, int index)
{
    float* arr = *(float**)((char*)self + 0xeb0);
    return arr[index];
}
