#pragma force_active on
extern "C" void fn_123_13A10(void* object, float x, float y)
{
    float* values = (float*)object;
    values[0] = x;
    values[1] = y;
}
