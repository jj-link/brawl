#pragma force_active on
struct Obj {
    char pad[0x40];
    float threshold;
    char pad2[0x24];
    void* c;
};
struct Matrix { float m[4][4]; } __attribute__((aligned(16)));
extern "C" void fn_8031CF54(Obj*, void*, void*, Matrix*, float*);
extern "C" void fn_8031D8FC(Obj*, const Matrix*);
extern "C" int fn_8031D6C0(Obj* self, void* arg) {
    Matrix matrix;
    float value;
    fn_8031CF54(self, arg, self->c, &matrix, &value);
    if (value < self->threshold) return 1;
    fn_8031D8FC(self, &matrix);
    return 0;
}