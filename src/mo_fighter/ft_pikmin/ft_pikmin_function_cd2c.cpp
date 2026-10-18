#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Owner {
    char pad[0xc];
    s32* m_counts;
};

extern "C" void fn_113_CD2C(Owner* self, u32 index) {
    self->m_counts[index]--;
}
