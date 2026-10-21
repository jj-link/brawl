#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int : 12;
    unsigned int field : 6;
    unsigned int : 14;
};

extern "C" void fn_27_CED70(Object* object, unsigned int value)
{
    object->field = value;
}
