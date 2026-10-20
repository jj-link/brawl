#pragma force_active on
struct ItemTable
{
    unsigned char reserved[8];
    int packed;
    int entries[9];
};

extern "C" int* fn_27_11B998(ItemTable* object, int index)
{
    int shift = object->packed >> 27;
    int result = shift + index;

    if (result >= 9)
        result -= 9;

    return &object->entries[result];
}
