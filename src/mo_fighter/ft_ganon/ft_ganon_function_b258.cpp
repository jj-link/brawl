#pragma force_active on
struct GanonState {
    unsigned int header[2];
    unsigned long long value;
};

extern "C" unsigned long long fn_109_B258(const GanonState* object) {
    return object->value;
}
