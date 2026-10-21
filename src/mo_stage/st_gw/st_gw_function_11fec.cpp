#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int : 4;
    unsigned int field : 2;
    unsigned int : 26;
};

extern "C" void fn_63_11FEC(Object* object, unsigned int value)
{
    object->field = value;
}
