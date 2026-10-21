#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int value : 6;
    unsigned int remaining : 26;
};

extern "C" void fn_27_296168(Object* object, unsigned int value)
{
    object->value = value;
}
