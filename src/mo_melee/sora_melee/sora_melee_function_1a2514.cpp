#pragma force_active on
struct Object {
    unsigned int unknown[2];
    unsigned int upper : 10;
    unsigned int field : 5;
    unsigned int lower : 17;
};

extern "C" void fn_27_1A2514(Object* object, unsigned int value)
{
    object->field = value;
}
