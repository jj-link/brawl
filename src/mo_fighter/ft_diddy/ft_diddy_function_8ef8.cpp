#pragma force_active on
struct DiddyKineticVector {
    float x, y, z;
};

extern "C" DiddyKineticVector* fn_115_8EF8(DiddyKineticVector* vector,
                                           float x, float y, float z) {
    vector->x = x;
    vector->y = y;
    vector->z = z;
    return vector;
}
