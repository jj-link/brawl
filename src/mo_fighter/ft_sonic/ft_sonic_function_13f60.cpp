#pragma force_active on
struct SonicScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" float fn_123_13F60(const SonicScalarPair* object) {
    return object->first * object->second;
}
