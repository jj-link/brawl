#pragma force_active on
struct PikminScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" float fn_113_1BDF4(const PikminScalarPair* object) {
    return object->first * object->second;
}
