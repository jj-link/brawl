#pragma force_active on
extern char lbl_80529CF8[];

typedef struct {
    char pad0[0x18];
    unsigned short value;
    char pad1[0x5C];
    unsigned char flags;
    char pad2[0x11];
} Entry;

void *fn_8023A038(unsigned int arg0) {
    Entry *p = (Entry *)(lbl_80529CF8 + 0x1F30);
    int i;

    for (i = 0; i < 16; i++, p++) {
        if ((p->flags & 0x80) && p->value == arg0) {
            return p;
        }
    }

    return 0;
}
