#pragma force_active on
struct WarioScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" float fn_110_12B1C(const WarioScalarPair* object) {
    return object->first * object->second;
}
