#pragma force_active on
typedef unsigned int u32;

struct Work {
    char pad[0x1c];
    u32* flags;
};

extern "C" u32 fn_119_98DC(Work* work, u32 mask, u32 index) {
    return (work->flags[index] & mask) != 0;
}
