#pragma force_active on
struct PitScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" float fn_112_112E0(const PitScalarPair* object) {
    return object->first * object->second;
}
