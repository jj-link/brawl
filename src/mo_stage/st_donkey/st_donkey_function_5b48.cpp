#pragma force_active on
extern "C" void fn_50_5B48(int *object, int value1, int value2)
{
    object[0x520 / sizeof(int)] = value1;
    object[0x528 / sizeof(int)] = value2;
}
