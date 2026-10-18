#pragma force_active on
extern "C" unsigned int* fn_99_8C00(unsigned int** object, unsigned int value, int index)
{
    unsigned int* array = object[3];
    array[index] = value;
    return array;
}
