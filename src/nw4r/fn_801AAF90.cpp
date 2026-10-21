#pragma force_active on
extern "C" {

extern void fn_801EC184(char*, int);

int fn_801AAF90(char* arg0, unsigned arg1, int arg2) {
    if (arg2 != 0 && arg1 < 3) {
        fn_801EC184(arg0 + arg1 * 0x30 + 0xC, arg2);
        return 1;
    }
    return 0;
}

}
