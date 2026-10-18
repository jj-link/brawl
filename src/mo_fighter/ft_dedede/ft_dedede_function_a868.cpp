#pragma force_active on
extern "C" void fn_117_A868(void* self, int value, int index)
{
    int* array = *(int**)((char*)self + 0xC);
    array[index] = value;
}
