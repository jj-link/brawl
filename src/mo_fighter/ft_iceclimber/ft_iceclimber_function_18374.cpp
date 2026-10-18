#pragma force_active on
struct IceClimberScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" float fn_105_18374(const IceClimberScalarPair* __restrict object) {
    return object->first * object->second;
}
