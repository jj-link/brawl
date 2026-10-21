#pragma force_active on
struct Object {
    unsigned char padding[0xA4];
    unsigned char : 1;
    unsigned char flag : 1;
    unsigned char : 6;
};

extern "C" void fn_41_33C0C(Object* object, unsigned int value) {
    object->flag = value;
}
