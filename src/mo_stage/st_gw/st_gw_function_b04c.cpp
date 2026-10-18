#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int value : 4;
    unsigned int remaining : 28;
};

extern "C" void fn_63_B04C(Object* object, unsigned int value)
{
    object->value = value;
}
