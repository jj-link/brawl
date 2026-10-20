#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int : 8;
    unsigned int field : 4;
    unsigned int : 20;
};

extern "C" void fn_63_B264(Object* object, unsigned int value)
{
    object->field = value;
}
