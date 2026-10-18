#pragma force_active on
extern "C" void fn_98_A130(void* object, int divisor, int index)
{
    if (divisor == 0)
        return;

    int* values = *reinterpret_cast<int**>(
        reinterpret_cast<char*>(object) + 0xC);
    values[index] /= divisor;
}
