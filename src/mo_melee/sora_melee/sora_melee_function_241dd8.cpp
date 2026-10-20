#pragma force_active on
extern "C" {
extern char* lbl_27_bss_5668;

bool fn_27_241DD8(unsigned char* p) {
    if (p[0x47] == 1) {
        return true;
    }
    return lbl_27_bss_5668 == 0;
}
}
