#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct fn_119_9A2C_Work {
    u8 pad[0xc];
    s32* m_intWorks;
};

extern "C" void fn_119_9A2C(fn_119_9A2C_Work* work, s32 value, u32 index) {
    work->m_intWorks[index] *= value;
}
