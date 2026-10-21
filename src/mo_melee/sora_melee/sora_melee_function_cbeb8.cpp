#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int upper : 8;
    unsigned int field : 4;
    unsigned int lower : 20;
};

extern "C" void fn_27_CBEB8(Object* object, unsigned int value)
{
    object->field = value;
}
