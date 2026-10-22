#pragma force_active on
extern int lbl_80529918[];
extern int fn_8023251C(int arg0);
extern void *fn_8022EE58(unsigned short size);
extern void fn_80232034(unsigned char *dst, const unsigned char *src);
extern void fn_802324E0(void *arg);
extern char *strncpy(char *dest, const char *src, unsigned long count);

void fn_80233C40(unsigned char *arg0) {
    unsigned char *result;

    fn_8023251C((int)((unsigned char *)lbl_80529918) + 0x58);
    result = (unsigned char *)fn_8022EE58(0x110);
    if (result != 0) {
        fn_80232034(result + 8, (const unsigned char *)lbl_80529918 + 0x1a);
        strncpy((char *)(result + 0xE), (char *)arg0 + 4, 0x20);
        *(unsigned short *)result = 0x204;
        fn_802324E0(result);
    }
}
