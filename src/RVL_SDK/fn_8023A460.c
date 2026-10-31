#pragma force_active on

extern char lbl_80529CF8[];
extern void fn_80238378(void);
extern void fn_8023A3B0(void);
extern void fn_80231FB0(char *p, int a, int b);
extern void fn_80245D40(void);

void fn_8023A460(void *arg0) {
    if (*(void **)(lbl_80529CF8 + 0x58C) == 0 ||
        *(void **)(lbl_80529CF8 + 0x58C) == arg0) {
        fn_80238378();
        fn_8023A3B0();
        *(unsigned int *)(lbl_80529CF8 + 0x58C) = (unsigned int)arg0;
        *(unsigned char *)(lbl_80529CF8 + 0x64E) = 0;
        *(unsigned char *)(lbl_80529CF8 + 0x64F) = 5;
        fn_80231FB0(lbl_80529CF8 + 0x574, 1, 4);
        fn_80245D40();
        if (*(void **)(lbl_80529CF8 + 0x568) != 0) {
            ((void (*)(int))*(void **)(lbl_80529CF8 + 0x568))(1);
        }
    }
}
