#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct FtSnakeWork {
    u8 pad[0xc];
    s32* m_counts;
};

extern "C" void fn_122_F7DC(FtSnakeWork* work, u32 index) {
    work->m_counts[index] += 1;
}
