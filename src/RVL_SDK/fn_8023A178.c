#pragma force_active on
extern char lbl_80529CF8[];

typedef struct {
    char pad0[12];
    unsigned int key;
    char pad1[0x66];
    unsigned char flags;
    char pad2[0x11];
} Entry;

void *fn_8023A178(void)
{
    unsigned int minKey = -1;
    Entry *p = (Entry *)(lbl_80529CF8 + 0x1F30);
    Entry *best = p;
    int i;

    for (i = 0; i < 16; i++, p++) {
        if ((p->flags & 0x80) && !(p->flags & 0x10)) {
            unsigned int key = p->key;
            if (key < minKey) {
                best = p;
                minKey = key;
            }
        }
    }
    if (minKey + 0x10000 != 0xFFFF)
        return best;

    p = (Entry *)(lbl_80529CF8 + 0x1F30);
    for (i = 0; i < 16; i++, p++) {
        if (p->flags & 0x80) {
            unsigned int key = p->key;
            if (key < minKey) {
                best = p;
                minKey = key;
            }
        }
    }
    return best;
}