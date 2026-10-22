#pragma force_active on
typedef unsigned short u16;
extern void fn_8023CAB0(int arg);
extern u16 fn_8023C3D0(void);
extern void fn_8023C3E0(void);
extern void *fn_8022EE58(unsigned short size);
extern void fn_802324E0(void *arg);
extern void fn_8023C784(void);
extern int lbl_80529918[];

void fn_80232CD0(void) {
    short *temp_r3;

    fn_8023CAB0(0);
    if (fn_8023C3D0() != 0) {
        fn_8023C3E0();
        ((void (*)(int, int))lbl_80529918[0])(4, 0);
        temp_r3 = (short *)fn_8022EE58(0x110);
        if (temp_r3 != 0) {
            *temp_r3 = 0x207;
            fn_802324E0(temp_r3);
        }
    } else if (lbl_80529918[2] == 0) {
        fn_8023C784();
    }
}
