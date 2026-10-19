#pragma force_active on
extern "C" const float lbl_95_rodata_C;

typedef unsigned char u8;
typedef unsigned int u32;

struct FtYoshiFloatWork {
    u8 pad[0x14];
    float* m_floatWorks;
};

extern "C" void fn_95_B868(FtYoshiFloatWork* work, float value, u32 index) {
    if (lbl_95_rodata_C != value) {
        work->m_floatWorks[index] /= value;
    }
}
