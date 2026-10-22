#pragma force_active on
extern void fn_8023BD10(void);
extern void fn_8023CB80(void);
extern char lbl_80529CF8[];

typedef void (*FnI)(int);
typedef void (*FnP)(void *);

void fn_8023A3B0(void) {
    unsigned char sp8;
    FnI f1;
    FnP f2;
    FnP f3;

    sp8 = 0xC;
    fn_8023CB80();
    fn_8023BD10();

    f1 = *(FnI *)(lbl_80529CF8 + 0x5A8);
    if (f1 != 0) {
        *(FnI *)(lbl_80529CF8 + 0x5A8) = 0;
        if (f1 != 0) {
            f1(0);
        }
    }

    f2 = *(FnP *)(lbl_80529CF8 + 0x5C4);
    if (f2 != 0) {
        *(FnP *)(lbl_80529CF8 + 0x5C4) = 0;
        if (f2 != 0) {
            f2(&sp8);
        }
    }

    f3 = *(FnP *)(lbl_80529CF8 + 0x5E0);
    if (f3 != 0) {
        *(FnP *)(lbl_80529CF8 + 0x5E0) = 0;
        if (f3 != 0) {
            f3(&sp8);
        }
    }
}
