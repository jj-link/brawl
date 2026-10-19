#pragma force_active on
struct ZakoState {
    unsigned int padding[2];
    unsigned long long value;
};

extern "C" unsigned long long fn_126_8904(const ZakoState* object) {
    return object->value;
}
