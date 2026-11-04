#pragma force_active on
extern char lbl_80529CF8[];

typedef struct {
    char a[8];
    char pad[0x12];
    unsigned char f;
    char pad2[1];
} E;

void *fn_8023C974(void *arg0) {
    unsigned short i;
    E *p;

    if (arg0 != 0) {
        i = (unsigned short)((((E *)((char *)arg0 - 8)) - ((E *)(lbl_80529CF8 + 0x16E4))) + 1);
        p = ((E *)(lbl_80529CF8 + 0x16E4)) + i;
        for (; i < 12; i++, p++) {
            if (p->f != 0) {
                return p->a + 8;
            }
        }
        return 0;
    }
    p = (E *)(lbl_80529CF8 + 0x16E4);
    for (i = 0; i < 12; i++, p++) {
        if (p->f != 0) {
            return p->a + 8;
        }
    }
    return 0;
}
