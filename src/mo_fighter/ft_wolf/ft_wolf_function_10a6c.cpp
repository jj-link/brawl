#pragma force_active on
struct WolfScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" float fn_125_10A6C(const WolfScalarPair* object) {
    return object->first * object->second;
}
