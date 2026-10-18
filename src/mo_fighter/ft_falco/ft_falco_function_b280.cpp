#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct ftWork {
    u8 pad[0xc];
    s32 *m_table;
};

extern "C" void fn_108_B280(ftWork *self, u32 index) {
    self->m_table[index]++;
}
