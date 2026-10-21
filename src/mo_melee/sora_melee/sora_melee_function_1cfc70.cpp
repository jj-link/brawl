#pragma force_active on
struct Object
{
    unsigned int padding[2];
    unsigned int : 10;
    unsigned int field : 5;
    unsigned int : 17;
};

extern "C" void fn_27_1CFC70(Object* object, unsigned int value)
{
    object->field = value;
}
