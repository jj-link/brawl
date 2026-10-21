#pragma force_active on
extern char lbl_80529918[];
extern void fn_8023F454(void (*)());
extern char* strncpy(char* dst, const char* src, unsigned long n);

void fn_80233B74(int a, int b, const char* src) {
    strncpy(lbl_80529918 + 0x20, src, 0x1F);
    fn_8023F454(fn_80233B74);
}
