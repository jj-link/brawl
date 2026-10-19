#pragma force_active on
struct Fn41C13CObject
{
    unsigned int pad[7];
    unsigned int *table;
};

extern "C" int fn_41_C13C(Fn41C13CObject *object, unsigned int mask, unsigned int index)
{
    return (object->table[index] & mask) != 0;
}
