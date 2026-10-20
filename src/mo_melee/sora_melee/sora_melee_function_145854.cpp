#pragma force_active on
typedef int s32;

extern "C" void fn_27_120218(char* obj, s32 type, s32 arg);
extern char** g_ftSlotManager;

extern "C" void fn_27_145854(s32 unused, s32 slot, s32 kind, s32 arg) {
    if (kind == 0x31) {
        fn_27_120218(*g_ftSlotManager + slot * 0x4d4, 0x15, arg);
    } else if (kind == 0x30) {
        fn_27_120218(*g_ftSlotManager + slot * 0x4d4, 0xb, arg);
    } else {
        fn_27_120218(*g_ftSlotManager + slot * 0x4d4, kind, arg);
    }
}
