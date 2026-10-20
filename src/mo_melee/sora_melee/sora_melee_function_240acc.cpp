#pragma force_active on
extern "C" void fn_27_240ACC(char* self, unsigned int a, unsigned int b)
{
    *(unsigned int*)(self + 0x54) = a;
    *(unsigned int*)(self + 0x5c) = b & 7;
}
