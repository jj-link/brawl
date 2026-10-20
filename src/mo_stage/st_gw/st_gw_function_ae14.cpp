#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int : 4;
    unsigned int flags : 2;
    unsigned int : 26;
};

extern "C" void fn_63_AE14(Object* object, unsigned int value)
{
    object->flags = value;
}
