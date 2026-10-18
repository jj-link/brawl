#pragma force_active on
extern "C" void fn_101_D494(void* object, int divisor, int index)
{
    if (divisor == 0)
        return;

    int* values = *reinterpret_cast<int**>(
        reinterpret_cast<unsigned char*>(object) + 0xC);
    values[index] /= divisor;
}
