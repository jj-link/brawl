#pragma force_active on
struct Object {
    unsigned int pad[2];
    unsigned int upper : 4;
    unsigned int value : 4;
    unsigned int lower : 24;
};

extern "C" void fn_27_19C4F0(Object* obj, unsigned int value)
{
    obj->value = value;
}
