#pragma force_active on
extern "C" {

struct SamusPair {
    unsigned char prefix[8];
    float first;
    float second;
};

float fn_94_1D950(const SamusPair* object) {
    return object->first * object->second;
}

}
