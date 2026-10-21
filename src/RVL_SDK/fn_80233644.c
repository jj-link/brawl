#pragma force_active on
extern void *fn_8022EE58(unsigned short size);
extern void *memcpy(void *dst, const void *src, unsigned long n);
extern int lbl_80529918[];

void fn_80233644(void *arg0) {
    void *p = fn_8022EE58(0x1C);
    ((void **)lbl_80529918)[0x74 / 4] = p;
    memcpy(p, arg0, 0x1C);
}
