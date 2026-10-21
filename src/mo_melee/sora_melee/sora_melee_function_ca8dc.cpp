#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int : 10;
    unsigned int value : 5;
    unsigned int : 17;
};

extern "C" void fn_27_CA8DC(Object* object, unsigned int value)
{
    object->value = value;
}
