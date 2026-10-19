#pragma force_active on
struct PokeScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" float fn_116_113BC(const PokeScalarPair* object) {
    return object->first * object->second;
}
