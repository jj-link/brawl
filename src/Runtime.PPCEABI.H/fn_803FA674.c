#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern char *lbl_8059FF60;
extern char *lbl_8059FF64;

char *strtok(char *arg0, const char *arg1) {
    u8 tbl[32];
    unsigned char *p;
    unsigned char c;
    char *tok;

    *(u32*)&tbl[0] = 0;
    *(u32*)&tbl[4] = 0;
    *(u32*)&tbl[8] = 0;
    *(u32*)&tbl[12] = 0;
    *(u32*)&tbl[16] = 0;
    *(u32*)&tbl[20] = 0;
    *(u32*)&tbl[24] = 0;
    *(u32*)&tbl[28] = 0;

    if (arg0 != 0) {
        lbl_8059FF64 = arg0;
    }

    p = (unsigned char *)arg1 - 1;
    while ((c = *++p) != 0) {
        tbl[(c >> 3) & 0x1F] |= (u8)(1 << (c & 7));
    }

    p = (unsigned char *)lbl_8059FF64 - 1;
    while ((c = *++p) != 0) {
        if (!(tbl[(c >> 3) & 0x1F] & (u8)(1 << (c & 7)))) {
            break;
        }
    }
    if (c == 0) {
        lbl_8059FF64 = lbl_8059FF60;
        return 0;
    }
    tok = (char *)p;
    while ((c = *++p) != 0) {
        if (tbl[(c >> 3) & 0x1F] & (u8)(1 << (c & 7))) {
            break;
        }
    }
    if (c == 0) {
        lbl_8059FF64 = lbl_8059FF60;
        return tok;
    }
    lbl_8059FF64 = (char *)p + 1;
    *p = 0;
    return tok;
}
