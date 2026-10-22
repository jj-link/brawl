#pragma force_active on
extern int lbl_80529918[];
extern int fn_8023251C(int arg0);
extern void *fn_8022EE58(unsigned short size);
extern void fn_80232034(unsigned char *dst, const unsigned char *src);
extern void fn_802324E0(void *arg);
extern char *strncpy(char *dest, const char *src, unsigned int n);

void fn_80233BB4(char *arg0) {
    char *result;

    fn_8023251C((int)lbl_80529918 + 0x58);
    result = (char *)fn_8022EE58(0x110);
    if (result) {
        fn_80232034((unsigned char *)result + 8, (const unsigned char *)(lbl_80529918[1] + 2));
        strncpy(result + 0xE, arg0 + 4, 0x20);
        *(short *)result = 0x204;
        fn_802324E0(result);
    }
}
