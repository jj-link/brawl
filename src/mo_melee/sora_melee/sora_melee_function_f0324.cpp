#pragma force_active on
struct Entry {
    int value[3];
};

struct Object {
    char padding[0x18];
    int flags;
};

extern "C" Entry *fn_27_F0324(Object *object, int index)
{
    int adjusted = object->flags >> 30;
    int result = adjusted + index;

    if (result >= 1)
        --result;

    return reinterpret_cast<Entry *>(
        reinterpret_cast<char *>(object) + 0x1C + result * 12);
}
