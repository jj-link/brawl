#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int : 6;
    unsigned int flags : 6;
    unsigned int : 20;
};

extern "C" void fn_48_BA08(Object* object, unsigned int value) {
    object->flags = value;
}
