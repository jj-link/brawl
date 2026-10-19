#pragma force_active on
struct IceClimberState {
    unsigned int header[2];
    unsigned long long value;
};

extern "C" unsigned long long fn_105_104A0(const IceClimberState* object) {
    return object->value;
}
