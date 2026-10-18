#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct ft_link_obj {
    u32 m_pad[3];
    s32* m_counts;
};

extern "C" void fn_93_B30C(ft_link_obj* self, u32 index) {
    self->m_counts[index]--;
}
