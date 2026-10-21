#pragma force_active on
struct Object {
    unsigned int unknown[2];
    unsigned int : 3;
    unsigned int field : 3;
    unsigned int : 26;
};

extern "C" void fn_27_19F090(Object* object, unsigned int value)
{
    object->field = value;
}
