#pragma force_active on
typedef void (*Callback)(void *, unsigned char, unsigned char, unsigned char);

typedef struct {
    Callback callback;
    unsigned char flags;
    unsigned char pad[3];
} Entry;

typedef struct {
    unsigned char pad[0x3c];
    unsigned char items[4][0x11c];
    unsigned char pad2[0xa8];
    Entry entries[2];
    unsigned char index;
    unsigned char selected;
} State;

extern State lbl_80529CF8;

void fn_8023DC04(void)
{
    Callback cb = 0;
    int item;

    if (lbl_80529CF8.selected != 0x80) {
        if (lbl_80529CF8.entries[lbl_80529CF8.selected].flags & 2) {
            cb = lbl_80529CF8.entries[lbl_80529CF8.selected].callback;
        }
    }

    item = 4;
    item += (lbl_80529CF8.entries[0].flags = 0);
    lbl_80529CF8.index = item;
    *((unsigned char *)&lbl_80529CF8 + 0x560) = 0;

    if (!cb) {
        return;
    }

    cb(lbl_80529CF8.items[item], 5, 12, 0);
}
