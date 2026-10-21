#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int high : 12;
    unsigned int field : 6;
    unsigned int low : 14;
};

extern "C" void fn_27_C452C(Object* object, unsigned int value)
{
    object->field = value;
}
