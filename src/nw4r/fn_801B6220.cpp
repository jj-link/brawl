#pragma force_active on
extern "C" void fn_801F1FF0(float *, float, float, float, float, float, float);
extern const float lbl_805A3408;
extern const float lbl_805A340C;
extern const float lbl_805A3410;
inline void helper(unsigned int *self, float a, float b, float c, float d, float e) {
    fn_801F1FF0((float *)((char *)self + 4), a, b, c, d, e, c - d);
    *self = (*self & ~1u) | 2u;
}
extern "C" void fn_801B6220(unsigned int *self, float value) {
    helper(self, lbl_805A3408, lbl_805A3408, lbl_805A340C, value * lbl_805A3410, lbl_805A3408);
}
