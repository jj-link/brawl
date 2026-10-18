#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

struct WorkHolder {
    u8 pad[0xc];
    s32* m_counts;
};

extern "C" void fn_119_99DC(WorkHolder* work, u32 index) {
    work->m_counts[index]--;
}
