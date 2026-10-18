#pragma force_active on
struct FtDonkeyScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" float fn_92_12928(const FtDonkeyScalarPair* object) {
    return object->first * object->second;
}
