#pragma force_active on
extern "C" void fn_27_A1FBC(int* object, int index, int value)
{
    *(int*)((char*)object + index * 4 + 28) = value;
}
