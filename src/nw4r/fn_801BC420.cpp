#pragma force_active on
extern "C" void fn_801BC420(float* arr, int idx, float val)
{
    *(float*)((char*)arr + idx * 4 + 0x2C) = val;
}
