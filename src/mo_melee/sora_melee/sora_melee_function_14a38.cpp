#pragma force_active on
struct Object {
    unsigned char padding[0x54];
    unsigned char flag : 1;
    unsigned char remaining : 7;
};

extern "C" void fn_27_14A38(Object* object, unsigned int value) {
    object->flag = value;
}
