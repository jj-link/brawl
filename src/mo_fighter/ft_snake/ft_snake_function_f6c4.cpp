#pragma force_active on
typedef unsigned int u32;

struct GeneralWork {
    unsigned char padding[0x1c];
    u32* flagWorks;
};

extern "C" u32 fn_122_F6C4(const GeneralWork* work, u32 mask, u32 index) {
    if (work->flagWorks[index] & mask) {
        return 1;
    }
    return 0;
}
