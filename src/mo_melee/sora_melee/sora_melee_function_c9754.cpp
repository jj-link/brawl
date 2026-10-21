#pragma force_active on
struct Object {
    unsigned int unused[2];
    unsigned int : 2;
    unsigned int value : 2;
    unsigned int : 28;
};

extern "C" void fn_27_C9754(Object* object, unsigned int value)
{
    object->value = value;
}
