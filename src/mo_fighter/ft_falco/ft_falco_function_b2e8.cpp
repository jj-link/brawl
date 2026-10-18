#pragma force_active on
typedef unsigned int u32;

struct FtWorkHolder {
    char pad[0xc];
    u32* m_works;
};

extern "C" void fn_108_B2E8(FtWorkHolder* self, u32 value, u32 index) {
    self->m_works[index] += value;
}
