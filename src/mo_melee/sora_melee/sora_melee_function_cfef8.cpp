#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int : 14;
    unsigned int value : 7;
    unsigned int : 11;
};

extern "C" void fn_27_CFEF8(Object* object, unsigned int value)
{
    object->value = value;
}
