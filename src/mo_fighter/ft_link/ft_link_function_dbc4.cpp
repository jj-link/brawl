#pragma force_active on
struct LinkState {
    unsigned int padding[2];
    unsigned long long value;
};

extern "C" unsigned long long fn_93_DBC4(const LinkState* object) {
    return object->value;
}
