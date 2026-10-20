#pragma force_active on
struct Object {
    unsigned char pad[8];
    int index;
};

extern "C" void *fn_27_1AF6FC(Object *object, int offset)
{
    int index = (object->index >> 22) + offset;
    if (index >= 0x13A)
        index -= 0x13A;

    return reinterpret_cast<char *>(object) + 0x0C + index * 4;
}
