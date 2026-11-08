#include <revolution/OS/OSError.h>
#include <types.h>
#pragma force_active on
extern char lbl_80466E68[];
extern char lbl_8059E984;
extern char lbl_8059E98C;
extern int fn_801D536C(void);
extern int fn_801DE38C(void);
extern int fn_801DE380(void);
extern int fn_801D712C(void);
extern int fn_801D7144(void);
extern int fn_801D7134(void);
extern int fn_801D714C(void);
void fn_801D59EC(void) {
    char *base = lbl_80466E68;
    s32 temp_r3, temp_r4;
    u32 tdev, version, builddate;
    u32 size;
    int arena;
    OSReport(base + 0x48);
    OSReport(base + 0x58, base + 0x70, base + 0x7c);
    OSReport(base + 0x88);
    temp_r3 = fn_801D536C();
    temp_r4 = temp_r3 & 0xF0000000;
    switch (temp_r4) {
    case 0:
        switch (temp_r3) {
        case 0x11: OSReport(base + 0x98); break;
        case 0x12: OSReport(base + 0xb0); break;
        case 0x20: OSReport(base + 0xcc); break;
        case 0x100: OSReport(&lbl_8059E984); break;
        default: OSReport(base + 0xe8, temp_r3); break;
        }
        break;
    case 0x10000000:
        switch (temp_r3) {
        case 0x10000021: OSReport(base + 0xf4); break;
        case 0x10000020: OSReport(base + 0x100); break;
        case 0x10000012: OSReport(base + 0x10c); break;
        case 0x10000011: OSReport(base + 0x118); break;
        case 0x10000010: OSReport(base + 0x124); break;
        case 0x10000008: OSReport(base + 0x130); break;
        default: OSReport(base + 0x148, temp_r3); break;
        }
        break;
    case 0x20000000:
        tdev = temp_r3 & 0x0FFFFFFF;
        OSReport(base + 0x164, tdev - 3);
        break;
    default:
        OSReport(&lbl_8059E98C, temp_r3);
        break;
    }
    version = *(u32 *)0xC0003140;
    builddate = *(u32 *)0xC0003144;
    OSReport(base + 0x180, (version >> 16) & 0xFF, (version >> 8) & 0xFF, version & 0xFF);
    OSReport(base + 0x19c,
             (u8)(((builddate >> 20) & 0xF) * 10 + ((builddate >> 16) & 0xF)),
             (u8)(((builddate >> 12) & 0xF) * 10 + ((builddate >> 8) & 0xF)),
             (u16)(((builddate >> 4) & 0xF) * 10 + (builddate & 0xF) + 2000));
    size = fn_801DE380() + fn_801DE38C();
    OSReport(base + 0x1a8, size >> 20);
    arena = fn_801D712C();
    OSReport(base + 0x1b8, fn_801D7144(), arena);
    arena = fn_801D7134();
    OSReport(base + 0x1d4, fn_801D714C(), arena);
}