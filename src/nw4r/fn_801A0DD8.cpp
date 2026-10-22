#pragma force_active on

extern "C" {
extern int fn_803F6150(const void*, const void*, unsigned long);
extern void* fn_801B5E38(void*, void*);
extern unsigned char lbl_804A4F00[0x614];
}

extern "C" void fn_801A0DD8(const int* arg0, int arg1) {
    int sp8 = *arg0;
    if (arg1 >= 0 && arg1 < 0x20 && sp8 != 0) {
        if (*(const int*)(lbl_804A4F00 + 4) == arg1) {
            if (fn_803F6150((void*)sp8, (void*)(lbl_804A4F00 + arg1 * 0x30 + 8), 0x30) == 0)
                return;
            *(int*)lbl_804A4F00 = 0;
        }
        fn_801B5E38((void*)&sp8, (void*)(lbl_804A4F00 + arg1 * 0x30 + 8));
    }
}
