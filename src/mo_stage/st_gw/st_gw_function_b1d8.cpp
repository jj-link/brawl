#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int upper : 4;
    unsigned int value : 4;
    unsigned int lower : 24;
};

extern "C" void fn_63_B1D8(Object* object, unsigned int value)
{
    object->value = value;
}
