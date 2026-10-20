#pragma force_active on
struct Object {
    unsigned char padding[8];
    unsigned int flags : 2;
    unsigned int remaining : 30;
};

extern "C" void fn_63_AF90(Object* object, unsigned int value) {
    object->flags = value;
}
