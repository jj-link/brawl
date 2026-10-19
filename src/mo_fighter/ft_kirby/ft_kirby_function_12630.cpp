#pragma force_active on
struct KirbyState {
    unsigned int header[2];
    unsigned long long value;
};

extern "C" unsigned long long fn_96_12630(const KirbyState* object) {
    return object->value;
}
