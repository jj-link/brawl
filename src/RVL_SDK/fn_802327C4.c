#include <string.h>
#pragma force_active on

extern void fn_80232108(void (*)(void));
extern void fn_80232118(void (*)(void));
extern void fn_802350CC(void);
extern void fn_80238958(unsigned short);
extern void fn_80238D24(unsigned short);
extern void fn_802393A0(void (*)(void));
extern void fn_8023B2D0(void (*)(void));
extern void fn_8023B3A4(void *);
extern void fn_8023B694(unsigned short);
extern void fn_8023F38C(void *, void *);
extern void fn_80243624(void);
extern void fn_8024AECC(void (*)(void), int);

extern void fn_80234204(void);
extern void fn_802340AC(void);
extern void fn_802345E8(void);
extern void fn_802346CC(void);
extern void fn_80234904(void);

extern unsigned char lbl_8040D698[];
extern unsigned char lbl_8040D7C8[];
extern unsigned char lbl_805298E8[];
extern unsigned char lbl_80529918[];
extern unsigned char lbl_80529994[];
extern unsigned char lbl_80529A98[];

void fn_802327C4(unsigned char *arg0) {
    unsigned char sp8[4];

    memset(lbl_80529918, 0, 0x7C);
    memset(lbl_80529A98, 0, 0x2E);
    memcpy(sp8, lbl_8040D698, 3);
    fn_8023B3A4(sp8);
    *(int *)(lbl_80529994 + 0x50) = *(int *)(arg0 + 8);
    fn_8023F38C(lbl_8040D7C8, lbl_80529994);
    fn_80238D24(*(unsigned short *)(lbl_8040D698 + 8));
    fn_8023B694(*(unsigned short *)(lbl_8040D698 + 6));
    fn_80238958(*(unsigned short *)(lbl_8040D698 + 4));
    fn_802393A0(fn_80234204);
    fn_8023B2D0(fn_802340AC);
    fn_80232108(fn_80234904);
    fn_80232118(fn_802346CC);
    fn_802350CC();
    memset(lbl_805298E8, 0, 0x2D);
    fn_80232118(fn_802346CC);
    fn_8024AECC(fn_802345E8, 0);
    fn_80243624();
}
