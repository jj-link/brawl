#include <mt/mt_prng.h>
#pragma force_active on

extern "C" int fn_8004D9E8(void*);
extern void* g_GameGlobal;
extern mtRand lbl_805A0420;
extern const float lbl_27_rodata_6008;

struct Entry {
    unsigned char bytes[4];
    short value;
};
extern Entry lbl_27_data_7AC98[];

extern "C" short fn_27_2C2D24(const char* str) {
    if (str == 0 || *str == 0)
        return 0xD3;
    if (!((unsigned char)*str & 0x80)) {
        if (fn_8004D9E8(g_GameGlobal)) {
            if (*str >= '0' && *str <= '9') return (short)(*str + 0x14);
            if (*str >= 'A' && *str <= 'Z') return (short)(*str + 0x0D);
            if (*str >= 'a' && *str <= 'z') return (short)(*str - 0x13);
        } else {
            if (*str >= '0' && *str <= '9') return (short)(*str + 0x38);
            if (*str >= 'A' && *str <= 'Z') return (short)(*str + 0x31);
            if (*str >= 'a' && *str <= 'z') return (short)(*str + 0x11);
        }
        if (*str == '.') return 0xCC;
        if (*str == ',') return 0xCC;
        if (*str == ' ') return 0xCB;
        if (*str == '?') return 0xCE;
        if (*str == '!') return 0xCF;
    } else if (((unsigned char)*str & 0xE0) != 0xC0 && ((unsigned char)*str & 0xF0) == 0xE0) {
        Entry* p = lbl_27_data_7AC98;
        for (unsigned int i = 0; i < 0xE7; i++, p++) {
            if (p->bytes[0] == (unsigned char)str[0] &&
                p->bytes[1] == (unsigned char)str[1] &&
                p->bytes[2] == (unsigned char)str[2]) {
                if (fn_8004D9E8(g_GameGlobal)) return p->value;
                short val = p->value;
                if (val >= 0x4E && val <= 0x67) return (short)(val + 0x24);
                if (val >= 0x44 && val <= 0x4D) return (short)(*(short*)((char*)p + 4) + 0x24);
            }
        }
    }
    return lbl_27_data_7AC98[(int)(lbl_27_rodata_6008 * lbl_805A0420.mtRand::randf())].value;
}