#pragma force_active on
struct Object
{
    char pad[0x51C];
    const float* values;
};

extern "C" float fn_50_5B54(const Object* object, unsigned int index)
{
    return object->values[index];
}
