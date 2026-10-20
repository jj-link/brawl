#pragma force_active on
struct KartVector {
    float unk0;
    float y;
    float z;
    float w;
};

extern "C" void fn_49_39B0(KartVector* vector, float x, float y, float z) {
    vector->y = x;
    vector->z = y;
    vector->w = z;
}
