#pragma force_active on
extern "C" void fn_99_8B40(void* const* container, int index, float value)
{
    float* array = (float*)container[5];
    array[index] = value;
}
