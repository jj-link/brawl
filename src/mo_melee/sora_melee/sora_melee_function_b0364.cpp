#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int value : 9;
    unsigned int rest : 23;
};

extern "C" void fn_27_B0364(Object* object, unsigned int value)
{
    object->value = value;
}
