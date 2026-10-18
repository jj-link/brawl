#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FtSamusWork {
    u32 pad[3];
    s32* values;
};

extern "C" void fn_94_B068(FtSamusWork* work, s32 value, u32 index) {
    work->values[index] *= value;
}
