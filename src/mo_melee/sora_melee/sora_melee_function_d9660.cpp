#pragma force_active on
struct Object {
    int padding[2];
    int value;
};

extern "C" void *fn_27_D9660(Object *object, int index)
{
    int sum = (object->value >> 27) + index;

    if (sum >= 12)
        sum -= 12;

    return reinterpret_cast<char *>(object) + sum * 0x30 + 0xC;
}
