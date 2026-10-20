#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int : 4;
    unsigned int value : 4;
    unsigned int : 24;
};

extern "C" void fn_63_B110(Object* object, unsigned int value)
{
    object->value = value;
}
