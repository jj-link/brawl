#pragma force_active on
extern "C" {
    void netReport__FPCce(const char*, ...);
    void clearSendBuffer__6NtSendFv(void* self);
    void fn_8014A060(void* arg0);
    void fn_80143C48(void* arg0, int arg1);
    void fn_8013DDEC(void* arg0);
    void fn_80148F30(void* arg0, int arg1, int arg2, int arg3);

    extern int gUnk805a03d8;
    extern void* g_NtSend;
    extern void* lbl_805A0434;
    extern char lbl_8045F280[];
    extern char lbl_8045F204[];

    int fn_80146718(void* arg0, int arg1, int arg2, int arg3) {
        if (gUnk805a03d8 != 3) {
            netReport__FPCce(lbl_8045F280, gUnk805a03d8);
            return 0;
        }
        *(int*)((char*)arg0 + 0x1C) = arg1;
        *(int*)((char*)arg0 + 0x20) = arg2;
        *(int*)((char*)arg0 + 0x24) = arg3;
        if (gUnk805a03d8 != 3) {
            netReport__FPCce(lbl_8045F204);
        } else {
            clearSendBuffer__6NtSendFv(g_NtSend);
            fn_8014A060(*(void**)((char*)arg0 + 0x30));
            fn_80143C48(*(void**)((char*)arg0 + 0x38), 0);
            fn_8013DDEC(*(void**)((char*)arg0 + 0x34));
        }
        fn_80148F30(lbl_805A0434, arg1, arg2, arg3);
        gUnk805a03d8 = 4;
        return 1;
    }
}