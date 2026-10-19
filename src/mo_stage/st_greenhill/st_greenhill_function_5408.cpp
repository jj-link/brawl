#pragma force_active on
struct GreenhillObject
{
    int header[2];
    int value;
};

extern "C" int* fn_72_5408(GreenhillObject* object, int index)
{
    int sum = (object->value >> 28) + index;

    if (sum >= 6)
    {
        sum -= 6;
    }

    return (int*)((char*)object + sum * 8 + 12);
}
