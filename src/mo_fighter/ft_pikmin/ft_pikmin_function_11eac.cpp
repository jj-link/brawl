#pragma force_active on
struct Object
{
    unsigned int padding[2];
    unsigned int : 4;
    unsigned int value : 2;
    unsigned int : 26;
};

extern "C" void fn_113_11EAC(Object* object, unsigned int value)
{
    object->value = value;
}
