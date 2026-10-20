#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void fn_27_11EF50(u8* self, s32 index);
extern "C" u8** g_ftSlotManager;

extern "C" void fn_27_109644(s32 unused, s32 slot, s32 index) {
    fn_27_11EF50(*g_ftSlotManager + slot * 0x4d4, index);
}
