#pragma force_active on
struct FalcoScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" float fn_108_10B24(const FalcoScalarPair* object) {
    return object->first * object->second;
}
