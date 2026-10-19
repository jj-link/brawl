#pragma force_active on
struct FloatPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" float fn_120_13B70(const FloatPair* object) {
    return object->first * object->second;
}
