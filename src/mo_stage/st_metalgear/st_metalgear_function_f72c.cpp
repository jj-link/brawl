#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int : 4;
    unsigned int field : 2;
    unsigned int : 26;
};

extern "C" void fn_71_F72C(Object* object, unsigned int value)
{
    object->field = value;
}
