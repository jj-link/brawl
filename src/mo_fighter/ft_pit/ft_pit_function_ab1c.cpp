#pragma force_active on
typedef unsigned int u32;

struct FtWorkTable {
    char pad[0xc];
    u32* values;
};

extern "C" void fn_112_AB1C(FtWorkTable* self, u32 value, u32 index) {
    self->values[index] += value;
}
