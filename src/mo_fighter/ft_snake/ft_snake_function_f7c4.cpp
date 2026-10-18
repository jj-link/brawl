#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FtSnakeWork {
    char pad[0xc];
    s32 *m_counts;
};

extern "C" void fn_122_F7C4(FtSnakeWork *self, u32 index) {
    self->m_counts[index] = self->m_counts[index] - 1;
}
