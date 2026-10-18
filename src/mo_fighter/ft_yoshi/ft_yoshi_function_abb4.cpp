#pragma force_active on
struct Vector3 {
    float x, y, z;
};

extern "C" Vector3* fn_95_ABB4(Vector3* vector, float x, float y, float z) {
    vector->x = x;
    vector->y = y;
    vector->z = z;
    return vector;
}
