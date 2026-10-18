#pragma force_active on
typedef unsigned int u32;

struct FtIkeWork {
    char pad[0x1c];
    u32 *m_table;
};

extern "C" {
void fn_119_9910(FtIkeWork *work, u32 index) {
    work->m_table[index] = 0;
}
}
