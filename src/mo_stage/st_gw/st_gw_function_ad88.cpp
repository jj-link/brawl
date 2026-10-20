#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int : 2;
    unsigned int flags : 2;
    unsigned int : 28;
};

extern "C" void fn_63_AD88(Object* object, unsigned int value) {
    object->flags = value;
}
