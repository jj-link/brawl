#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FtWork {
    char pad[0xc];
    s32* counts;
};

extern "C" void fn_105_DDAC(FtWork* work, u32 index) {
    work->counts[index]++;
}
