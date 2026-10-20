#pragma force_active on
struct Matrix {
    float values[16];
};

struct Object {
    unsigned int unused;
    void* data;
    unsigned char padding[0x10];
    float value;
};

extern "C" void fn_801341D8(void*, Matrix*);
extern "C" const float lbl_27_rodata_400;
extern "C" const float lbl_27_rodata_404;

extern "C" float fn_27_30240(Object self) {
    if (lbl_27_rodata_400 != self.value) {
        Matrix matrix;
        fn_801341D8(self.data, &matrix);
        return (matrix.values[8] - matrix.values[6]) / self.value;
    }
    return lbl_27_rodata_404;
}
