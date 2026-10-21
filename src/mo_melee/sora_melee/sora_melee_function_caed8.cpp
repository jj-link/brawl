#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int : 5;
    unsigned int field : 5;
    unsigned int : 22;
};

extern "C" void fn_27_CAED8(Object* object, unsigned int value)
{
    object->field = value;
}
