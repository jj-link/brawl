#pragma force_active on

extern "C" {
extern int g_NtMatchingStatus;
extern int g_NtAIDBitmap;
extern int lbl_805A03E0;
extern unsigned char lbl_805A0410;
extern unsigned char lbl_805A0414;
extern unsigned char lbl_805A0418[8];
extern unsigned char lbl_8059E742;
extern unsigned char lbl_8059E743;
extern unsigned char lbl_8059E744;
extern unsigned char lbl_8059E745;

void* memset(void* s, int c, unsigned long n);

void fn_8014A060(void* arg0) {
    g_NtMatchingStatus = 5;
    lbl_805A03E0 = 5;
    *(char*)((char*)arg0 + 0x33CE) = 0;
    *(char*)((char*)arg0 + 0x33F5) = 0;
    *(char*)((char*)arg0 + 0x33F6) = 0;
    *(int*)((char*)arg0 + 0x3404) = 0;
    memset((void*)&lbl_805A0410, 0, 4);
    g_NtAIDBitmap = 0;
    lbl_805A0414 = 0;
    lbl_8059E742 = 0xFF;
    lbl_8059E745 = 0xFF;
    lbl_8059E743 = 0xFF;
    lbl_8059E744 = 0xFF;
    lbl_805A0418[0] = 0;
    lbl_805A0418[1] = 0;
    lbl_805A0418[2] = 0;
    lbl_805A0418[3] = 0;
    lbl_805A0418[4] = 0;
    lbl_805A0418[5] = 0;
    lbl_805A0418[6] = 0;
    lbl_805A0418[7] = 0;
}
}
