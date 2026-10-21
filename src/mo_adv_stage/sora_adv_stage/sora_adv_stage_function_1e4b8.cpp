#pragma force_active on
struct Object
{
    unsigned int padding[2];
    unsigned int upper : 12;
    unsigned int value : 6;
    unsigned int lower : 14;
};

extern "C" void fn_40_1E4B8(Object* object, unsigned int value)
{
    object->value = value;
}
