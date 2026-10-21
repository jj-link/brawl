#pragma force_active on
unsigned char *fn_8023A038(void);

int fn_80240F8C(void) {
    unsigned char *p = fn_8023A038();
    if (p != 0 && (p[0x81] & 0x40)) {
        return 1;
    }
    return 0;
}
