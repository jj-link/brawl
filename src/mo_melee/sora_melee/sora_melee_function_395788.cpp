#pragma force_active on
extern "C" void fn_27_395788(void* self, unsigned int value)
{
    unsigned int* field = (unsigned int*)((char*)self + 8);
    unsigned int oldValue = *field;
    *field = __rlwimi(oldValue, value, 24, 4, 7);
}
