#include <types.h>
#include <ft/ft_manager.h>
#pragma force_active on
struct CheckObject { virtual void f0(); virtual void f1(); virtual void f2(); virtual s32 check(); };
extern "C" s32 fn_27_1448C0(s32, s32, s32, s32, s32, u8, u8);
extern "C" s32 fn_27_145028(s32);
extern int lbl_27_bss_31F8;
static inline bool checkSlots(s32 entry, s32 owner, char* obj, u8& k);
static inline bool checkOthers(s32 entry, s32 owner, s32* sm, s32& j, s32& off, char*& obj, u8& k);
extern "C" s32 fn_27_120818(char* p) {
    if (*(s32*)(p + 4) != 0) return 0;
    if (((CheckObject*)(p + 0x178))->check() > 0 || ((CheckObject*)(p + 0x204))->check() > 0) return 0;
    if (*(s32*)(p + 0x160) != 6) {
        s32 entry; u8 k; s32 j; s32 owner; s32* sm; s32 off; char* obj; u8 i;
        for (i = 0; i < *(u8*)(p + 0x158); ++i) {
            owner = *(s32*)(p + 0x174);
            sm = (s32*)g_ftSlotManager;
            j = 0;
            off = 0;
            entry = *(s32*)(p + i * 0x54 + 8);
            if (!checkOthers(entry, owner, sm, j, off, obj, k)) return 0;
        }
    }
    if (fn_27_145028(lbl_27_bss_31F8) == 0) return 0;
    return 1;
}
static inline bool checkSlots(s32 entry, s32 owner, char* obj, u8& k) {
    for (k = 0; k < 8; ++k) {
        char* slot = obj + k * 0x30;
        s32 slotOwner = *(s32*)(slot + 0x338);
        if (slotOwner == -1) continue;
        if (entry != *(s32*)(slot + 0x330)) continue;
        if (owner != -1 && owner != slotOwner) continue;
        u8 flag = *(u8*)(obj + 0x15E);
        
        if (((u32)(-((((char*)g_ftManager)[0x6C] >> 6) & 1) | ((((char*)g_ftManager)[0x6C] >> 6) & 1)) >> 31) == 1 && ((((char*)g_ftManager)[0x6E] >> 2) & 1) == 0) flag = 0;
        if (fn_27_1448C0(lbl_27_bss_31F8, *(s32*)(slot + 0x330), *(s32*)(obj + 0x174), slotOwner, *(s32*)(slot + 0x334), *(u8*)(obj + 0x15B), flag) == 0) return false;
    }
    return true;
}
static inline bool checkOthers(s32 entry, s32 owner, s32* sm, s32& j, s32& off, char*& obj, u8& k) {
    while (j < sm[1]) {
        if (j != owner) {
            obj = (char*)sm[0] + off;
            if (*(u8*)(obj + 0x15D) == 0 && *(s32*)(obj + 0x160) == 6) {
                if (!checkSlots(entry, owner, obj, k)) return 0;
            }
        }
        off += 0x4D4;
        ++j;
    }
    return true;
}