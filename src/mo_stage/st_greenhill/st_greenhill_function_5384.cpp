#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int value : 4;
    unsigned int remainder : 28;
};

extern "C" void fn_72_5384(Object* object, unsigned int value)
{
    object->value = value;
}
