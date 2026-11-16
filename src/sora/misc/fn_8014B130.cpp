#pragma force_active on
extern "C" {
void fn_8013F658(int);
void netReport__FPCce(const char*, ...);
void fn_800C8F68(const char*, ...);
void fn_80146FCC(int);
int fn_8014727C(int, int);
void fn_800D125C(int);
void fn_8014403C(int);
extern char lbl_8045F7A8[];
extern int g_muWifiInterfaceTask;
extern int lbl_805A0390;
extern int lbl_805A0434;
extern int lbl_805A03A8;
extern int lbl_805A03E0;
extern int lbl_805A03E8;
extern int lbl_805A03F4;
extern int g_NtMatchingStatus;

void fn_8014B130(int arg0) {
    char* base = lbl_8045F7A8;
    int taskPtr = g_muWifiInterfaceTask;
    int sel;
    fn_8013F658(lbl_805A0390);
    char* self = (char*)lbl_805A0434;
    if (*(int*)(self + 0x34a4) != 0) {
        *(int*)(self + 0x34a4) = 0;
        netReport__FPCce(base + 0x7ac);
    }
    *(int*)(self + 0x3430) = 0;
    ((unsigned char*)lbl_805A0434)[0x34ac] = (unsigned char)(((unsigned char*)lbl_805A0434)[0x34ac] & 0xFFFFFF00);
    switch (lbl_805A03E8) {
    case 7: {
        int v;
        switch (lbl_805A03F4) {
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            v = 1;
            break;
        default:
            v = 0;
            break;
        }
        if (v == 0) goto L;
        sel = 1;
        break;
    }
    case 2:
    case 3:
    case 6:
    case 14:
        sel = 1;
        break;
    default:
    L:
        sel = 0;
        break;
    }
    if (sel != 0) {
        int r = fn_8014727C((int)lbl_805A0434, arg0);
        netReport__FPCce(base + 0x10c8, r);
        fn_800C8F68(base + 0x10e8, fn_8014727C((int)lbl_805A0434, arg0));
    } else {
        int r = fn_8014727C((int)lbl_805A0434, arg0);
        netReport__FPCce(base + 0x10fc, r);
        fn_800C8F68(base + 0x1110, fn_8014727C((int)lbl_805A0434, arg0));
        if (g_NtMatchingStatus != 0xc) {
            lbl_805A03E0 = g_NtMatchingStatus;
        }
        lbl_805A03E8 = arg0;
        fn_80146FCC(0xc);
    }
    fn_800D125C(taskPtr);
    fn_8014403C(lbl_805A03A8);
}
}