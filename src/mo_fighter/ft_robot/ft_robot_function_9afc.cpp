#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FtRobotWork {
    char pad[0xC];
    s32* m_counts;
};

extern "C" void fn_120_9AFC(FtRobotWork* work, u32 index) {
    work->m_counts[index]--;
}
