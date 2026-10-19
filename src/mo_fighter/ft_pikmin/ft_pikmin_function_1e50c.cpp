#pragma force_active on
extern "C" {
int fn_113_1E568(float);

int fn_113_1E50C(float* self) {
    int result = 0;
    float a = self[0];
    if (fn_113_1E568(a) != 0) {
        float b = self[1];
        if (fn_113_1E568(b) != 0) {
            result = 1;
        }
    }
    return result;
}
}
