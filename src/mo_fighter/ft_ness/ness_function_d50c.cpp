#pragma force_active on
struct NessTable {
    unsigned char padding[12];
    unsigned int* entries;
};

extern "C" unsigned int fn_101_D50C(NessTable* object, unsigned int index)
{
    return object->entries[index];
}
