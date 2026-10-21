#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int : 7;
    unsigned int value : 7;
    unsigned int : 18;
};

extern "C" void fn_27_1D0324(Object* object, unsigned int value)
{
    object->value = value;
}
