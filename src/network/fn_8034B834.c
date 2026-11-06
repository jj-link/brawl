#include <types.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on
extern int lbl_805A0FA8;
extern int lbl_8059F0B0;
extern char lbl_8048AA60[];
typedef struct MatchKeyEntry {
    unsigned char enabled;
    unsigned char is_string;
    unsigned short padding;
    void *name;
    void *value;
} MatchKeyEntry;
extern MatchKeyEntry lbl_805338B0[];
extern char lbl_8059F164[4];
extern char lbl_8059F168[5];
extern char lbl_8059F170[5];
extern char lbl_8059F0DC[4];
extern char lbl_8059F178[5];
extern char lbl_8059F180[8];
extern char lbl_8059F188[8];
extern char lbl_8059F190[5];
extern char lbl_8059F198[8];
extern char lbl_8059F1A0[8];
extern void fn_80335638(int, const char *, ...);
extern int fn_8037929C(char *, int);
extern int fn_8037933C(char *, const char *);
extern unsigned char fn_8033A77C(void);
extern int fn_8033A7DC(void);
extern int fn_8033AA6C(void);
extern s64 fn_803F1470(s64, s64);
static inline const char *get_name(int key, const char *base) {
    switch (key) {
    case 8: return base + 0x2110;
    case 10: return base + 0x211C;
    case 50: return lbl_8059F164;
    case 51: return lbl_8059F168;
    case 52: return lbl_8059F170;
    case 53: return lbl_8059F0DC;
    case 54: return lbl_8059F178;
    case 55: return lbl_8059F180;
    case 56: return lbl_8059F188;
    case 57: return lbl_8059F190;
    case 58: return lbl_8059F198;
    default: return lbl_8059F1A0;
    }
}
static inline int get_level(int elapsed) {
    int level = lbl_8059F0B0;
    if (level != -1) return level;
    level = (elapsed + 4999) / 5000;
    if (level > 10) level = 10;
    return level;
}
static inline int get_suspend(void) {
    int result = -1;
    int mask;
    int flag;
    if (lbl_805A0FA8 == 0) return 0;
    mask = *(int *)(lbl_805A0FA8 + 0x1C);
    mask &= fn_8033A7DC();
    if (fn_8033AA6C()) {
        if (*(int *)(lbl_805A0FA8 + 0x1B4) == 15) flag = 1;
        else flag = 0;
    } else flag = 1;
    if (!flag) mask &= ~(1 << fn_8033A77C());
    if ((mask ^ fn_8033A7DC()) == 0) result = 1;
    else if ((mask & fn_8033A7DC()) == 0) result = 0;
    if (result != -1) *(int *)(lbl_805A0FA8 + 0x28) = (result == 1);
    return *(int *)(lbl_805A0FA8 + 0x28);
}
void fn_8034B834(int key, char *buffer) {
    const char *base = lbl_8048AA60;
    const char *name;
    int value;
    int index;
    char *entry;
    switch (key) {
    case 8:
        fn_8037929C(buffer, *(unsigned char *)(lbl_805A0FA8 + 0x14));
        fn_80335638(0x200, base + 0x2128, key, get_name(key, base), *(unsigned char *)(lbl_805A0FA8 + 0x14));
        break;
    case 10:
        fn_8037929C(buffer, *(unsigned char *)(lbl_805A0FA8 + 0x19));
        fn_80335638(0x200, base + 0x2128, key, get_name(key, base), *(unsigned char *)(lbl_805A0FA8 + 0x19));
        break;
    case 50:
        fn_8037929C(buffer, *(int *)(lbl_805A0FA8 + 0x218));
        fn_80335638(0x200, base + 0x2128, key, get_name(key, base), *(int *)(lbl_805A0FA8 + 0x218));
        break;
    case 51:
        fn_8037929C(buffer, *(unsigned char *)(lbl_805A0FA8 + 0x16));
        fn_80335638(0x200, base + 0x2128, key, get_name(key, base), *(unsigned char *)(lbl_805A0FA8 + 0x16));
        break;
    case 52:
        fn_8037929C(buffer, *(int *)(lbl_805A0FA8 + 0x34));
        fn_80335638(0x200, base + 0x2128, key, get_name(key, base), *(int *)(lbl_805A0FA8 + 0x34));
        break;
    case 53:
        fn_8037929C(buffer, 11);
        fn_80335638(0x200, base + 0x2128, key, get_name(key, base), 11);
        break;
    case 54:
        fn_8037929C(buffer, 1);
        fn_80335638(0x200, base + 0x2128, key, get_name(key, base), 1);
        break;
    case 55:
        fn_8037929C(buffer, (int)*(unsigned char *)(lbl_805A0FA8 + 0x17) == 2 ? *(int *)(lbl_805A0FA8 + 0x4A0) : 0);
        fn_80335638(0x200, base + 0x2128, key, get_name(key, base), (int)*(unsigned char *)(lbl_805A0FA8 + 0x17) == 2 ? *(int *)(lbl_805A0FA8 + 0x4A0) : 0);
        break;
    case 56:
        value = get_level((int)fn_803F1470(*(s64 *)(lbl_805A0FA8 + 0x4C0), (u32)(OS_TIME_SPEED / 1000)));
        fn_8037929C(buffer, value);
        name = get_name(key, base);
        value = get_level((int)fn_803F1470(*(s64 *)(lbl_805A0FA8 + 0x4C0), (u32)(OS_TIME_SPEED / 1000)));
        fn_80335638(0x200, base + 0x2128, key, name, value);
        break;
    case 57:
        fn_8037929C(buffer, *(unsigned char *)(lbl_805A0FA8 + 0x17));
        fn_80335638(0x200, base + 0x2128, key, get_name(key, base), *(unsigned char *)(lbl_805A0FA8 + 0x17));
        break;
    case 58:
        value = get_suspend();
        fn_8037929C(buffer, value);
        fn_80335638(0x200, base + 0x2128, key, get_name(key, base), value);
        break;
    default:
        index = key - 100;
        if (index >= 0 && index < 154) {
            if (lbl_805338B0[index].enabled) {
                if (lbl_805338B0[index].is_string)
                    fn_8037933C(buffer, lbl_805338B0[index].value);
                else
                    fn_8037929C(buffer, *(int *)lbl_805338B0[index].value);
            }
        }
        break;
    }
}
