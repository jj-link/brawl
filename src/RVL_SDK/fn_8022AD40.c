#include <types.h>
#include <revolution/OS/OSAlarm.h>
#pragma force_active on

typedef struct {
    u8 hci_version;
    u16 hci_revision;
    u8 lmp_version;
    u16 manufacturer;
    u16 lmp_subversion;
} LocalVersion;

extern u8 lbl_804FB4A0[];
extern char lbl_8047E8D0[];
extern u8 lbl_8047EE6C[];
extern u32 lbl_805A0CEC;
extern u32 lbl_805A0CF4;
extern u8 lbl_805A0CE8;

extern u8 fn_8022AC2C(void);
extern void fn_8022C568(void);
extern void fn_8022E928(const char *, ...);
extern int fn_8023B358(LocalVersion *);
extern int fn_8023B734(void *, void (*)(u8 *));
extern int fn_8023B45C(u16, u8, u8 *, void (*)(s32));
extern void fn_8022C0EC(s32);
extern void fn_8022DDBC(u8 *);

void fn_8022AD40(void)
{
    char *cfg = lbl_8047E8D0;
    u8 *base = lbl_804FB4A0;

    switch (base[0xF]) {
    case 1:
        if (*(u32 *)(base + 0x740) == 1) {
            base[0xE] = 1;
            fn_8023B734(0, fn_8022DDBC);
        }
        base[0xF] = 2;
        break;
    case 2:
        base[0xF] = fn_8022AC2C();
        break;
    case 3: {
        u8 next;
        if (base[0xE] == 0) {
            LocalVersion version;

            OSCancelAlarm((OSAlarm *)(base + 0x710));
            fn_8023B358(&version);
            fn_8022E928(cfg + 0x340, version.hci_version);
            fn_8022E928(cfg + 0x358, version.hci_revision);
            fn_8022E928(cfg + 0x370, version.lmp_version);
            fn_8022E928(cfg + 0x388, version.lmp_subversion);
            fn_8022E928(cfg + 0x3A0, version.manufacturer);
            fn_8022E928(cfg + 0x3B8, version.hci_revision & 0xFFF);
            if ((version.hci_revision & 0xFFF) == 0xA7) {
                int i;

                fn_8022E928(cfg + 0x3E0);
                lbl_805A0CF4 = 0;
                lbl_805A0CEC = 0;
                for (i = 0; i < 4; ++i) {
                    lbl_805A0CEC <<= 8;
                    lbl_805A0CEC += lbl_8047EE6C[3 - i];
                    lbl_805A0CF4 <<= 8;
                    lbl_805A0CF4 += lbl_8047EE6C[7 - i];
                }
                fn_8023B45C(0xFC4F, 1, &lbl_805A0CE8, fn_8022C0EC);
            } else {
                fn_8022C568();
            }
            next = 4;
        } else {
            next = 2;
        }
        base[0xF] = next;
        break;
    }
    }
}
