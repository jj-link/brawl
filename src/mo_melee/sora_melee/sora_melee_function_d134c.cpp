#pragma force_active on
struct Object {
    unsigned int pad[2];
    unsigned int high : 8;
    unsigned int value : 8;
    unsigned int low : 16;
};

extern "C" void fn_27_D134C(Object* object, unsigned int value) {
    object->value = value;
}
