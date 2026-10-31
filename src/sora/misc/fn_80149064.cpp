#pragma force_active on

extern "C" void netReport__FPCce(const char*, ...);
extern "C" void fn_80146FCC(int);

extern int g_NtMatchingStatus;
extern int lbl_805A03FC;
extern int lbl_805A0400;
extern int lbl_805A0404;
extern int* lbl_805A0434;
extern char lbl_8045FF54[];

extern "C" int fn_80149064(void* self, int arg1, int arg2) {
    if (g_NtMatchingStatus != 5) {
        return 0;
    }

    int zero = 0;
    lbl_805A03FC = arg1;
    lbl_805A0404 = arg2;
    lbl_805A0400 = zero;

    ((char*)lbl_805A0434)[0x33F4] = zero;
    ((char*)lbl_805A0434)[0x33F5] = zero;
    ((char*)lbl_805A0434)[0x33F6] = zero;
    *(int*)((char*)lbl_805A0434 + 0x34A4) = zero;
    ((char*)lbl_805A0434)[0x34AA] = zero;
    ((char*)lbl_805A0434)[0x34AB] = zero;

    char* object = (char*)self;
    *(int*)(object + 0x3428) = zero;
    *(int*)(object + 0x342C) = zero;

    if (*(int*)(object + 0x34A4) != 0) {
        *(int*)(object + 0x34A4) = zero;
        netReport__FPCce(lbl_8045FF54);
    }

    *(int*)(object + 0x3430) = zero;
    fn_80146FCC(6);
    return 1;
}
