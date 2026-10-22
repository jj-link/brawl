#pragma force_active on
extern char lbl_80529CF8[];

typedef struct { char a[8]; char pad[0x12]; unsigned char f; char pad2[1]; } E;

void *fn_8023C8BC(void) {
    unsigned char i;
    E *p = (E *)(lbl_80529CF8 + 0x16E4);
    for (i = 0; i < 12; i++, p++) {
        if (p->f != 0) return p->a + 8;
    }
    return 0;
}
