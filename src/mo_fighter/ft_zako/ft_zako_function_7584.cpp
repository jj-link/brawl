#pragma force_active on
extern "C" void fn_126_7584(void* self, unsigned int index, float value)
{
    float* arr = *(float**)((char*)self + 0x14);
    arr[index] *= value;
}
