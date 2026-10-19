#pragma force_active on
struct Object {
    unsigned int pad[2];
    unsigned long long value;
};

extern "C" unsigned long long fn_121_DBC0(const Object* object) {
    return object->value;
}
