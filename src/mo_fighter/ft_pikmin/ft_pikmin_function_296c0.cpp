#pragma force_active on
struct PikminVector {
    float x;
    float y;
    float z;
};

extern "C" {
extern void* g_cmAIController;
extern float lbl_113_rodata_150;
PikminVector* fn_113_A1D0(PikminVector* vector, float x, float y, float z);
void fn_8009FCC8(void* controller, void* vec, float* out);

void fn_113_296C0() {
    float buf[2];
    PikminVector vec;
    void* controller = g_cmAIController;
    if (controller != 0) {
        float f = lbl_113_rodata_150;
        buf[0] = f;
        buf[1] = f;
        PikminVector* r = fn_113_A1D0(&vec, f, f, f);
        fn_8009FCC8(controller, r, buf);
    }
}
}
