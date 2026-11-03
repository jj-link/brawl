#pragma force_active on
extern "C" {
extern int gUnk805a03d8;
extern void* g_muWifiInterfaceTask;
extern char lbl_8045F2B8[];
extern char lbl_8045F2F0[];
extern int lbl_805A0434;
void netReport__FPCce(const char*, ...);
int fn_80149644(char* self);
void fn_80146950(void* arg0);
}

extern "C" int fn_80146878(void* arg0, int arg1) {
    int value = gUnk805a03d8;
    if (value < 3 || value >= 7) {
        netReport__FPCce(lbl_8045F2B8);
        return 0;
    }
    if (value == 6) {
        netReport__FPCce(lbl_8045F2F0, *(unsigned char*)((char*)arg0 + 0x28));
        if (arg1 == 0) {
            *(unsigned char*)((char*)arg0 + 0x28) = 0;
        }
        return 0;
    }
    *(unsigned char*)((char*)arg0 + 0x28) = (unsigned char)arg1;
    int* p = (int*)((char*)g_muWifiInterfaceTask + 0xfcc);
    *p &= 0x00FFFFFF;
    fn_80149644((char*)lbl_805A0434);
    if (gUnk805a03d8 != 4) {
        return 1;
    }
    gUnk805a03d8 = 6;
    fn_80146950(arg0);
    return 1;
}