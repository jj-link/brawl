#pragma force_active on
extern int fn_803D4CB8(void);

int fn_803D5168(unsigned int arg0) {
    if (arg0 >= 0x64) {
        return 0;
    }
    return fn_803D4CB8() != 0;
}
