#pragma force_active on
extern "C" void fn_96_F500(float *const *container, unsigned int index, float value)
{
    float *array = container[5];
    array[index] = value;
}
