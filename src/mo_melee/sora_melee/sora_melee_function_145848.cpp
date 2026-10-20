#pragma force_active on
extern "C" {
typedef unsigned int u32;
typedef int s32;
extern s32 fn_27_122270(char* self, s32 a, u32 b);
extern char* g_ftSlotManager;

s32 fn_27_145848(char* dummy, s32 a, u32 b) {
    return fn_27_122270(g_ftSlotManager, a, b);
}
}
