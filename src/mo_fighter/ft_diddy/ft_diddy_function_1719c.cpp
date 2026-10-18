#pragma force_active on
struct DiddyScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" float fn_115_1719C(const DiddyScalarPair* object) {
    return object->first * object->second;
}
