#pragma force_active on
struct FighterVector {
    float x, y, z;
};

extern "C" {
extern const float lbl_108_rodata_8;
void fn_108_AA84(FighterVector* vector, float x, float y, float z);

void fn_108_D6F4(FighterVector* vector) {
    fn_108_AA84(vector, lbl_108_rodata_8, lbl_108_rodata_8, lbl_108_rodata_8);
}
}
