#pragma force_active on
struct KoopaState {
    unsigned int header[2];
    unsigned long long value;
};

extern "C" unsigned long long fn_102_B100(const KoopaState* object) {
    return object->value;
}
