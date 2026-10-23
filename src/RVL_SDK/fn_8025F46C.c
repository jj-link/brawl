#include <revolution/OS/OSFastCast.h>
#pragma force_active on

extern void OSRegisterVersion(const char *);
extern int lbl_8059EE40;
extern unsigned int lbl_80532018[10];
extern unsigned int lbl_80532140[4];
extern int lbl_805A0D40;

int fn_8025F46C(void) {
    OSRegisterVersion((const char *)lbl_8059EE40);

    lbl_80532018[0] = 0xE0000000;
    lbl_80532018[1] = 0xE0002000;
    lbl_80532018[2] = 0xE0002800;
    lbl_80532140[0] = 0xE0000000;
    lbl_80532140[1] = 0xE0002A00;
    lbl_80532140[2] = 0xE0003480;

    OSInitFastCast();

    lbl_805A0D40 = 1;
    return 1;
}
