#pragma force_active on
extern "C" void fn_99_8B98(void* object, int divisor, int index)
{
    if (divisor != 0) {
        int* values = *reinterpret_cast<int**>(
            static_cast<unsigned char*>(object) + 0x0C);
        values[index] /= divisor;
    }
}
