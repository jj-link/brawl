#include <revolution/OS/OSCache.h>
#pragma force_active on

extern int lbl_805A0AD8;
extern int lbl_805A0ADC;
extern int lbl_805A0AE0;
extern int lbl_805A0AE4;
extern int lbl_805A0AE8;
extern int lbl_805A0AEC;
extern int lbl_805A0AF0;
extern int lbl_805A0AF4;
extern int lbl_805A0AF8;
extern int lbl_805A0AFC;
extern int lbl_805A0B00;
extern int lbl_805A0B04;
extern int lbl_805A0B08;
extern int lbl_805A0B0C;
extern int lbl_805A0B10;
extern int lbl_805A0B14;
extern int lbl_805A0B18;
extern int lbl_805A0B1C;
extern int lbl_805A0B20;
extern int lbl_805A0B24;
extern unsigned char lbl_804E89E0[0x78];

void fn_80201270(int *arg0, int *arg1, short *arg2);
void fn_802012DC(int *arg0, int *arg1, short *arg2);

void fn_80201348(void) {
    fn_80201270(&lbl_805A0B24, (int *)(lbl_804E89E0 + 0x00), (short *)(lbl_804E89E0 + 0x04));
    fn_80201270(&lbl_805A0B20, (int *)(lbl_804E89E0 + 0x06), (short *)(lbl_804E89E0 + 0x0A));
    fn_80201270(&lbl_805A0B1C, (int *)(lbl_804E89E0 + 0x0C), (short *)(lbl_804E89E0 + 0x10));
    fn_80201270(&lbl_805A0B18, (int *)(lbl_804E89E0 + 0x12), (short *)(lbl_804E89E0 + 0x16));
    fn_80201270(&lbl_805A0B14, (int *)(lbl_804E89E0 + 0x18), (short *)(lbl_804E89E0 + 0x1C));
    fn_80201270(&lbl_805A0B10, (int *)(lbl_804E89E0 + 0x1E), (short *)(lbl_804E89E0 + 0x22));
    fn_80201270(&lbl_805A0B0C, (int *)(lbl_804E89E0 + 0x24), (short *)(lbl_804E89E0 + 0x28));
    fn_80201270(&lbl_805A0B08, (int *)(lbl_804E89E0 + 0x2A), (short *)(lbl_804E89E0 + 0x2E));
    fn_80201270(&lbl_805A0B04, (int *)(lbl_804E89E0 + 0x30), (short *)(lbl_804E89E0 + 0x34));
    fn_80201270(&lbl_805A0B00, (int *)(lbl_804E89E0 + 0x36), (short *)(lbl_804E89E0 + 0x3A));
    fn_80201270(&lbl_805A0AFC, (int *)(lbl_804E89E0 + 0x3C), (short *)(lbl_804E89E0 + 0x40));
    fn_80201270(&lbl_805A0AF8, (int *)(lbl_804E89E0 + 0x42), (short *)(lbl_804E89E0 + 0x46));
    fn_802012DC(&lbl_805A0AF4, (int *)(lbl_804E89E0 + 0x48), (short *)(lbl_804E89E0 + 0x4C));
    fn_802012DC(&lbl_805A0AF0, (int *)(lbl_804E89E0 + 0x54), (short *)(lbl_804E89E0 + 0x58));
    fn_802012DC(&lbl_805A0AEC, (int *)(lbl_804E89E0 + 0x60), (short *)(lbl_804E89E0 + 0x64));
    fn_802012DC(&lbl_805A0AE8, (int *)(lbl_804E89E0 + 0x6C), (short *)(lbl_804E89E0 + 0x70));
    fn_802012DC(&lbl_805A0AE4, (int *)(lbl_804E89E0 + 0x4E), (short *)(lbl_804E89E0 + 0x52));
    fn_802012DC(&lbl_805A0AE0, (int *)(lbl_804E89E0 + 0x5A), (short *)(lbl_804E89E0 + 0x5E));
    fn_802012DC(&lbl_805A0ADC, (int *)(lbl_804E89E0 + 0x66), (short *)(lbl_804E89E0 + 0x6A));
    fn_802012DC(&lbl_805A0AD8, (int *)(lbl_804E89E0 + 0x72), (short *)(lbl_804E89E0 + 0x76));
    DCFlushRange(lbl_804E89E0, 0x78);
}
