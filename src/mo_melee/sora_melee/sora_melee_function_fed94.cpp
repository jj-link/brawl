#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int upper : 12;
    unsigned int value : 6;
    unsigned int lower : 14;
};

extern "C" void fn_27_FED94(Object* object, unsigned int value)
{
    object->value = value;
}
