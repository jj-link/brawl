#pragma force_active on
extern char lbl_80529994[];
int fn_80234110(int);
int fn_8023251C(int);

int fn_802340D4(unsigned char* p) {
    if (p[0xc] != 0) {
        char* b = lbl_80529994;
        b[0x6c] = p[8];
        *(unsigned short*)(b + 0x70) = *(unsigned short*)(p + 0xa);
        return fn_80234110(0);
    }
    return fn_8023251C((int)(lbl_80529994 + 0x54));
}
