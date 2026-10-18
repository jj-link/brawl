#pragma force_active on
typedef unsigned int u32;

struct FtRobotWork {
    u32 m_unk0;
    u32 m_unk4;
    u32 m_unk8;
    u32* m_values;
};

extern "C" void fn_120_9B7C(FtRobotWork* work, u32 value, u32 index) {
    work->m_values[index] += value;
}
