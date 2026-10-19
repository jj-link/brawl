#pragma force_active on
struct KineticVector {
    float x, y, z;
};

extern "C" KineticVector* fn_123_12FF0(KineticVector* vector,
                                       float x, float y, float z) {
    vector->x = x;
    vector->y = y;
    vector->z = z;
    return vector;
}
