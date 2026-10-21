#pragma force_active on
extern void *fn_8022EE58(unsigned short size);
extern void *memcpy(void *dst, const void *src, unsigned long n);
extern char lbl_80529918[];

void fn_8023368C(void *arg0) {
    void *p = fn_8022EE58(0x18);
    *(void **)(lbl_80529918 + 0x74) = p;
    memcpy(p, arg0, 0x18);
}
