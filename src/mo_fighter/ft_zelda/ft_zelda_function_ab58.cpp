#pragma force_active on
struct Fn104AB58Object
{
    char pad[12];
    void **items;
};

extern "C" void *fn_104_AB58(Fn104AB58Object *object, unsigned int index)
{
    return object->items[index];
}
