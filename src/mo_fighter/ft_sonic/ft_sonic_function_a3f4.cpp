#pragma force_active on
typedef unsigned int u32;

struct FlagHolder {
    char pad[0x1c];
    u32* flags;
};

extern "C" void fn_123_A3F4(FlagHolder* obj, u32 mask, u32 index) {
    obj->flags[index] &= ~mask;
}
