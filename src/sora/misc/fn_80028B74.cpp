#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_80228154(int arg0);
extern "C" void fn_80228138(int arg0);

extern "C" void *g_gfHomeMenu;
extern "C" void (*lbl_805A0044)(void);

extern "C" void fn_80028B74(int arg0) {
    int flag;
    u8 *p;
    if (lbl_805A0044 != 0) {
        lbl_805A0044();
    }
    p = (u8 *)g_gfHomeMenu;
    if (p != 0) {
        flag = 0;
        if (((p[0xB1] >> 4) & 1) || *(int *)(p + 0x9C) != 0) {
            flag = 1;
        }
        if (flag != 0) {
            fn_80228154(arg0);
            return;
        }
    }
    fn_80228138(0);
    fn_80228138(1);
    fn_80228138(2);
    fn_80228138(3);
}
