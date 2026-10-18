#pragma force_active on
extern "C" void fn_101_D40C(unsigned char* self, int index, float value)
{
    float* arr = *reinterpret_cast<float**>(self + 0x14);
    arr[index] -= value;
}
