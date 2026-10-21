#pragma force_active on
extern unsigned char lbl_80529858[0x90];
void fn_802325EC(void* p);

void fn_802324AC(void) {
    unsigned char* p = lbl_80529858;
    if (p[0x7c] == 0) {
        fn_802325EC(p + 0x68);
    }
}
