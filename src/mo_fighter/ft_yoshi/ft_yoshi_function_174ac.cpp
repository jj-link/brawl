#pragma force_active on
struct YoshiScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" float fn_95_174AC(const YoshiScalarPair* object) {
    return object->first * object->second;
}
