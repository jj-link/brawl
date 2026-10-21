#pragma force_active on
struct Object {
    unsigned int pad[2];
    unsigned int : 10;
    unsigned int value : 10;
    unsigned int : 12;
};

extern "C" void fn_27_1A5F40(Object* object, unsigned int value)
{
    object->value = value;
}
