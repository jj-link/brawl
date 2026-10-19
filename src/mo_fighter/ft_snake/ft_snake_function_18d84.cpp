#pragma force_active on
struct SnakeScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" float fn_122_18D84(const SnakeScalarPair* object) {
    return object->first * object->second;
}
