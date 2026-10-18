#pragma force_active on
extern "C" void fn_108_B228(char* work, unsigned int index, float value)
{
    float* arr = *(float**)(work + 0x14);
    arr[index] += value;
}
