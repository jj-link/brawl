#pragma force_active on
// Constant remains owned by the original module's read-only data unit.
extern "C" const float lbl_107_rodata_D0;

struct FloatQuad {
    float v[4];
};

extern "C" void fn_107_166C8(FloatQuad* object) {
    object->v[3] = lbl_107_rodata_D0;
    object->v[2] = lbl_107_rodata_D0;
}
