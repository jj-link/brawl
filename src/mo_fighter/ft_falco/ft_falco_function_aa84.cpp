#pragma force_active on
struct FighterVector {
    float x, y, z;
};

extern "C" void fn_108_AA84(FighterVector* vector, float x, float y, float z) {
    vector->x = x;
    vector->y = y;
    vector->z = z;
}
