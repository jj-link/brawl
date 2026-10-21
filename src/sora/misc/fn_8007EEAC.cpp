#pragma force_active on
extern "C" {
struct CmdFlags {
    char pad;
    unsigned char flag;
};
extern CmdFlags lbl_805A024C;
extern char lbl_8049DDF0[];
int DVDGetCommandBlockStatus(void* block);

int fn_8007EEAC(void) {
    if (lbl_805A024C.flag != 0) {
        if (DVDGetCommandBlockStatus(lbl_8049DDF0 + 0x3C) == 0) {
            return 1;
        }
    }
    return 0;
}
}
