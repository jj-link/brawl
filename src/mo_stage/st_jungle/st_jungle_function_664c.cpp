#pragma force_active on
struct Object
{
    unsigned int padding[2];
    unsigned int : 2;
    unsigned int value : 2;
    unsigned int : 28;
};

extern "C" void fn_51_664C(Object* object, unsigned int value)
{
    object->value = value;
}
