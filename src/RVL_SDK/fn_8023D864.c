#pragma force_active on
extern char lbl_80529CF8[];
extern void* memset(void* dst, int c, unsigned long n);
void fn_8023CD18(void);
void fn_80237F00(void);
void fn_80240618(unsigned char val);
void fn_8023E554(void);
void fn_8023A310(void);

void fn_8023D864(void) {
    memset(lbl_80529CF8, 0, 0x27c4);
    lbl_80529CF8[0x27c0] = 0;
    fn_8023CD18();
    fn_80237F00();
    fn_80240618(2);
    fn_8023E554();
    fn_8023A310();
}
