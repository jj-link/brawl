#pragma force_active on
typedef unsigned int u32;

struct FtWorkPtrs {
    char pad[0xC];
    int* m_intWorks;
};

extern "C" void fn_97_B3F8(FtWorkPtrs* work, u32 index) {
    work->m_intWorks[index]--;
}
