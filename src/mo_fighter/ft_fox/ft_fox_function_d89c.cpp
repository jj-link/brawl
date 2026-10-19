#pragma force_active on
struct FoxState {
    unsigned int header[2];
    unsigned long long value;
};

extern "C" unsigned long long fn_97_D89C(const FoxState* object) {
    return object->value;
}
