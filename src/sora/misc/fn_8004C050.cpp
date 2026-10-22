#pragma force_active on
extern "C" {
void memset(void*, int, unsigned long);
extern unsigned long lbl_8059C800;
}

extern "C" void fn_8004C050(unsigned char* arg0) {
    if (*(unsigned long*)arg0 == lbl_8059C800) {
        unsigned char* q = arg0 + 0xBC;
        unsigned char* p = arg0;
        int i = 0;
        do {
            memset(q, 0, 0xC);
            i++;
            p[0xC8] = 0x78;
            q += 0x5C;
            p += 0x5C;
        } while (i < 7);
    }
}
