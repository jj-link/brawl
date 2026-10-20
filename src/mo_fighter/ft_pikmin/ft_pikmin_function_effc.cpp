#pragma force_active on
struct PikminState {
    unsigned int header[2];
    unsigned long long value;
};

extern "C" unsigned long long fn_113_EFFC(const PikminState* object) {
    return object->value;
}
