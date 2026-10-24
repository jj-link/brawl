#pragma force_active on
extern int lbl_8059FC38;
extern void *fn_80212588(int);
extern char lbl_80491398[];
extern char lbl_8059FC48;
void OSReport(const char *msg, ...);

void fn_8038F4C0(void) {
    char *base = lbl_80491398;
    if (lbl_8059FC38 >= 0) {
        void *r = fn_80212588(lbl_8059FC38);
        if (r == 0) {
            lbl_8059FC38 = -1;
            return;
        }
        OSReport(base + 0x10, base + 0x28, 0xA4, base + 0x58);
        OSReport(base + 0x34, r);
        OSReport(&lbl_8059FC48);
    }
}
