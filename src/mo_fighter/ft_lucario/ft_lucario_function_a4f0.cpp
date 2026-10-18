#pragma force_active on
extern "C" void fn_118_A4F0(void* object, int divisor, int index)
{
    if (divisor != 0) {
        int* values = *(int**)((char*)object + 0xC);
        values[index] /= divisor;
    }
}
