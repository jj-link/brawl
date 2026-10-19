#pragma force_active on
typedef unsigned int u32;

struct Work {
    char pad[0x1c];
    const u32* flags;
};

extern "C" bool fn_93_B20C(const Work* work, u32 mask, u32 index) {
    return (work->flags[index] & mask) != 0;
}
