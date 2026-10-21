#pragma force_active on
struct Object {
    unsigned int unused[2];
    unsigned int value : 3;
    unsigned int remaining : 29;
};

extern "C" void fn_27_FF200(Object* object, unsigned int value)
{
    object->value = value;
}
