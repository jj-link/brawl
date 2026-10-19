#pragma force_active on
extern "C" const float lbl_119_rodata_1C;

typedef unsigned int u32;

struct FtIkeWork {
    char pad[0x14];
    float* field_14;
};

extern "C" void fn_119_9944(FtIkeWork* work, u32 index, float value) {
    if (lbl_119_rodata_1C != value) {
        work->field_14[index] /= value;
    }
}
