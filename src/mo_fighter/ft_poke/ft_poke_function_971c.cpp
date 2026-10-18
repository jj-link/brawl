#pragma force_active on
struct FtPokeVector {
    float x, y, z;
};

extern "C" void fn_116_971C(FtPokeVector* vector, float x, float y, float z) {
    vector->x = x;
    vector->y = y;
    vector->z = z;
}
