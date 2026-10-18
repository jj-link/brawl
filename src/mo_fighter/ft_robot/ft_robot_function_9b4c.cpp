#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct WorkHolder {
    u8 pad[0xC];
    s32* m_values;
};

extern "C" void fn_120_9B4C(WorkHolder* work, s32 value, u32 index) {
    work->m_values[index] *= value;
}
