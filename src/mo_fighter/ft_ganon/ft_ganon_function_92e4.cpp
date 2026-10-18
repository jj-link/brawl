#pragma force_active on
typedef unsigned int u32;

struct FtWork {
    u32 pad[3];
    u32* counts;
};

extern "C" void fn_109_92E4(FtWork* work, u32 index) {
    work->counts[index]++;
}
