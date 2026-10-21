#pragma force_active on
struct Object {
    unsigned char padding[0x9C];
    unsigned int unused : 3;
    unsigned int flag : 1;
    unsigned int remaining : 28;
};

extern "C" void fn_27_413A0(Object* object, unsigned int value)
{
    object->flag = value;
}
