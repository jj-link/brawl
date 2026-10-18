#pragma force_active on
typedef unsigned int u32;

struct FlagWork {
    char pad[0x1c];
    u32* flags;
};

extern "C" void fn_92_99EC(FlagWork* work, u32 mask, u32 index) {
    work->flags[index] &= ~mask;
}
