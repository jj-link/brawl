#pragma force_active on
struct PikminVector {
    float x, y, z;
};

extern "C" PikminVector* fn_113_A1D0(PikminVector* vector,
                                     float x, float y, float z) {
    vector->x = x;
    vector->y = y;
    vector->z = z;
    return vector;
}
