#pragma force_active on
extern char lbl_80529CF8[];
extern char lbl_80480F14[];
extern void fn_802319FC(int, void*, int);
extern void* fn_8022EFF8(int);
extern void fn_8024602C(void*, int, int, int);

int fn_8023B80C(int arg0, int arg1, int arg2, int arg3) {
    void* p;
    if (*(int*)(lbl_80529CF8 + 0x570) != 0) {
        return 2;
    }
    if (*(unsigned char*)(lbl_80529CF8 + 0x27C0) >= 4) {
        fn_802319FC(0xD0003, &lbl_80480F14, arg0);
    }
    if ((unsigned)arg0 > 0xB) {
        arg0 = 0xB;
    }
    p = fn_8022EFF8(2);
    if (p != 0) {
        *(int*)(lbl_80529CF8 + 0x570) = arg3;
        fn_8024602C(p, arg0, arg1, arg2);
        return 0;
    }
    return 3;
}