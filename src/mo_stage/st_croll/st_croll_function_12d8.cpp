#pragma force_active on
struct Vector3 {
    float x;
    float y;
    float z;
};

extern "C" void fn_90_12D8(Vector3* vector, float x, float y, float z) {
    vector->x = x;
    vector->y = y;
    vector->z = z;
}
