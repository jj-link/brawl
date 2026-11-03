#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" {
bool fn_8004F4A0(int);
int fn_8004F740(int);
int fn_8004F654(void);
u32 fn_8004E7C8(void*);
u32 fn_8004E7EC(void*);
u32 fn_8004F3BC(u8);

int fn_2_21678(int unused, u32 kind) {
    switch (kind) {
    case 0x3: return fn_8004F4A0(0);
    case 0x4: return fn_8004F4A0(1);
    case 0x5: return fn_8004F4A0(2);
    case 0x6: return fn_8004F4A0(3);
    case 0x7: return fn_8004F4A0(5);
    case 0x8: return fn_8004F4A0(6);
    case 0xA: return fn_8004F4A0(7);
    case 0xB: return fn_8004F4A0(8);
    case 0xC: return fn_8004F4A0(0xC);
    case 0xD: return fn_8004F4A0(0xD);
    case 0xE: return fn_8004F4A0(0xE);
    case 0xF: return fn_8004F4A0(0x10);
    case 0x10: return fn_8004F4A0(0x17);
    case 0x11: return fn_8004F4A0(0x18);
    case 0x12: return fn_8004F4A0(0x19);
    case 0x13: return fn_8004F4A0(0x1A);
    case 0x14: return fn_8004F4A0(0x1B);
    case 0x15: return fn_8004F4A0(0x1C);
    case 0x16: return fn_8004F4A0(0x1D);
    case 0x17: return fn_8004F4A0(0x23);
    case 0x18: return fn_8004F4A0(0x25);
    case 0x19: return fn_8004F4A0(9);
    case 0x1A: return fn_8004F4A0(0xA);
    case 0x1B: return fn_8004F4A0(0xB);
    case 0x1C: return fn_8004F4A0(0x13);
    case 0x1D: return fn_8004F4A0(0x14);
    case 0x1E: return fn_8004F4A0(0x15);
    case 0x1F: return fn_8004F4A0(0x16);
    case 0x20: return fn_8004F4A0(0x24);
    case 0x21: return fn_8004F4A0(0x26);
    case 0x24: return fn_8004F4A0(0x28);
    case 0x25: return fn_8004F4A0(0x29);
    case 0x26: return fn_8004F4A0(0x2A);
    case 0x27: return fn_8004F4A0(0x2B);
    case 0x2D: return fn_8004F740(3);
    case 0x2E: return fn_8004F740(5);
    case 0x2F: return fn_8004F740(6);
    case 0x30: return fn_8004F740(8);
    case 0x31: return fn_8004F740(0xA);
    case 0x32: return fn_8004F740(0xB);
    case 0x33: return fn_8004F740(0xC);
    case 0x34: return fn_8004F740(0xD);
    case 0x35: return fn_8004F740(0xE);
    case 0x36: return fn_8004F740(0x13);
    case 0x37: return fn_8004F740(0x14);
    case 0x38: return fn_8004F740(0x16);
    case 0x39: return fn_8004F740(0x17);
    case 0x3A: return fn_8004F740(0x19);
    case 0x3B: return fn_8004F740(0x1C);
    case 0x3C: return fn_8004F740(0x1D);
    case 0x3D: return fn_8004F740(0x1E);
    case 0x3E: return fn_8004F740(0x20);
    case 0x3F: return fn_8004F740(0x21);
    case 0x40: return fn_8004F740(0x22);
    case 0x41: return fn_8004F740(0x24);
    case 0x42: return fn_8004F740(4);
    case 0x43: return fn_8004F740(7);
    case 0x44: return fn_8004F740(9);
    case 0x45: return fn_8004F740(0x15);
    case 0x46: return fn_8004F740(0x18);
    case 0x47: return fn_8004F740(0x1F);
    case 0x48: return fn_8004F740(0x23);
    case 0x49: return fn_8004F740(0x25);
    case 0x4A: return fn_8004F740(0x32);
    case 0x4B: return fn_8004F740(0x30);
    case 0x4C: return fn_8004F740(0x2C);
    case 0x4D: return fn_8004F740(0x2B);
    case 0x4E: return fn_8004F740(0x2D);
    case 0x4F: return fn_8004F740(0x2E);
    case 0x50: return fn_8004F740(0x31);
    case 0x22: return 0;
    case 0x23: return fn_8004F4A0(0x27);
    case 0x9: return fn_8004F654() != 0;
    case 0x1:
        if (fn_8004E7C8(g_GameGlobal) == 0) {
            return 0;
        }
        return fn_8004E7EC(g_GameGlobal) != 0;
    case 0x2C: {
        s32 i;
        s32 count = 0;
        for (i = 0; i < 6; i++) {
            if (fn_8004F3BC((u8)i) == 1) {
                count++;
            }
        }
        return count >= 6;
    }
    case 0x5D:
    case 0x5E:
    case 0x5F:
    case 0x60:
    case 0x61:
    case 0x62:
    case 0x63:
        return (*(u32*)((char*)g_GameGlobal->m_record + 0x804)) >> 31;
    case 0x64: return fn_8004F654() != 0;
    default: return 1;
    }
}
}
