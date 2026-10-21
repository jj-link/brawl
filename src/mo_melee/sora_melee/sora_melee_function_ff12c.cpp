#pragma force_active on
struct Object
{
    unsigned int padding[2];
    unsigned int : 4;
    unsigned int field : 2;
    unsigned int : 26;
};

extern "C" void fn_27_FF12C(Object* object, unsigned int value)
{
    object->field = value;
}
