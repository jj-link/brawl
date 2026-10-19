#pragma force_active on
struct WarioState {
    unsigned int padding[2];
    unsigned long long value;
};

extern "C" unsigned long long fn_110_B93C(const WarioState* object) {
    return object->value;
}
