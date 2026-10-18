#pragma force_active on
typedef unsigned int u32;

struct SonicWork {
    char pad[0x1c];
    u32 *table;
};

extern "C" void fn_123_A40C(SonicWork *self, u32 index) {
    self->table[index] = 0;
}
