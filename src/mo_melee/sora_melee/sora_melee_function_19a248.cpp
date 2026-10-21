#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int value : 5;
    unsigned int rest : 27;
};

extern "C" void fn_27_19A248(Object* object, unsigned int value) {
    object->value = value;
}
