#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int field : 6;
    unsigned int remaining : 26;
};

extern "C" void fn_54_10148(Object* object, unsigned int value) {
    object->field = value;
}
