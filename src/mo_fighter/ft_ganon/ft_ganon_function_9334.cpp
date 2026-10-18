#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct WorkArray {
    char pad[0xc];
    s32* m_values;
};

extern "C" {
void fn_109_9334(WorkArray* work, s32 value, u32 index) {
    work->m_values[index] -= value;
}
}
