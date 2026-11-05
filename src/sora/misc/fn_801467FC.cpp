#pragma force_active on
extern "C" {
    void netReport__FPCce(const char*, ...);
    int fn_80149064(void* self, int arg1, int arg2);
    extern int gUnk805a03d8;
    extern int g_NtAIDBitmap;
    extern unsigned char lbl_805A0414;
    extern unsigned char lbl_8059E742;
    extern unsigned char lbl_8059E745;
    extern void* lbl_805A0434;
    extern char lbl_8045F280[];

    int fn_801467FC(void* arg0, int arg1, int arg2) {
        if (gUnk805a03d8 != 3) {
            netReport__FPCce(lbl_8045F280, gUnk805a03d8);
            return 0;
        }
        g_NtAIDBitmap = 0;
        lbl_805A0414 = 0;
        lbl_8059E742 = 0xFF;
        lbl_8059E745 = 0xFF;
        *(int*)((char*)arg0 + 0x1C) = arg1;
        *(int*)((char*)arg0 + 0x20) = arg2;
        *(int*)((char*)arg0 + 0x24) = 0;
        fn_80149064(lbl_805A0434, arg1, arg2);
        gUnk805a03d8 = 4;
        return 1;
    }
}
