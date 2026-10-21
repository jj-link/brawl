#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int prefix : 3;
    unsigned int value : 3;
    unsigned int suffix : 26;
};

extern "C" void fn_27_3902F8(Object* object, unsigned int value) {
    object->value = value;
}
