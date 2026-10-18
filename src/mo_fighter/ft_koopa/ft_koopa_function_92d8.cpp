#pragma force_active on
typedef unsigned int u32;

struct FtKoopaWork {
    u32 pad[3];
    u32* m_values;
};

extern "C" void fn_102_92D8(FtKoopaWork* work, u32 value, u32 index) {
    work->m_values[index] += value;
}
