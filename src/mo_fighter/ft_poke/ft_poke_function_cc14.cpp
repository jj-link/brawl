#pragma force_active on
struct PokeState {
    unsigned int padding[2];
    unsigned long long value;
};

extern "C" unsigned long long fn_116_CC14(const PokeState* object) {
    return object->value;
}
