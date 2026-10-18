#pragma force_active on
struct Object {
    unsigned int pad[2];
    unsigned int upper : 8;
    unsigned int value : 4;
    unsigned int lower : 20;
};

extern "C" void fn_63_AF74(Object* object, unsigned int value) {
    object->value = value;
}
