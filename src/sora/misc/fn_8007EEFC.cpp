#pragma force_active on
extern "C" {
extern unsigned char lbl_805A024C;
extern unsigned char lbl_8049DDF0[0xD8];
int fn_801F6524(void* p);

void fn_8007EEFC(void) {
    unsigned char* flag = (unsigned char*)&lbl_805A024C + 1;
    if (*flag != 0) {
        fn_801F6524(&lbl_8049DDF0[0x3c]);
        *flag = 0;
    }
}
}
