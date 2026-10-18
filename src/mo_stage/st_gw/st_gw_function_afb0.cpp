#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int : 2;
    unsigned int field : 2;
    unsigned int : 28;
};

extern "C" void fn_63_AFB0(Object* object, unsigned int value)
{
    object->field = value;
}
