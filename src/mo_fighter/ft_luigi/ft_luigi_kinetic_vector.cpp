struct LuigiKineticVector {
    float x, y, z;
};

extern "C" LuigiKineticVector* fn_99_C610(LuigiKineticVector* vector,
                                         float x, float y, float z) {
    vector->x = x;
    vector->y = y;
    vector->z = z;
    return vector;
}
