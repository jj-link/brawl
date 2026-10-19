#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned long long value;
};

extern "C" unsigned long long fn_118_C4C4(const Object* object) {
    return object->value;
}
