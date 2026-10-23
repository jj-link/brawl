#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern void fn_80231FB0(void *, int, int);
extern void fn_80238378(void);
extern void fn_8023A3B0(void);
extern void fn_80245D40(void);
extern char lbl_80529CF8[];

void fn_8023A4FC(u32 arg0) {
    if (*(s32 *)(lbl_80529CF8 + 0x58C) == 0 ||
        *(u32 *)(lbl_80529CF8 + 0x58C) == arg0 ||
        *(u32 *)(lbl_80529CF8 + 0x620) == arg0) {
        fn_80238378();
        fn_8023A3B0();
        *(void **)(lbl_80529CF8 + 0x620) = (void *)arg0;
        *(unsigned char *)(lbl_80529CF8 + 0x64E) = 0;
        *(unsigned char *)(lbl_80529CF8 + 0x64F) = 5;
        fn_80231FB0(lbl_80529CF8 + 0x574, 1, 4);
        fn_80245D40();
        if (*(void **)(lbl_80529CF8 + 0x568) != 0) {
            ((void (*)(int))*(void **)(lbl_80529CF8 + 0x568))(1);
        }
    }
}
