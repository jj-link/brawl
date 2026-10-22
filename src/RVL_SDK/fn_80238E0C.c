#pragma force_active on
extern char lbl_80529CF8[];

typedef unsigned short u16;

u16 fn_80238E0C(void) {
    char *base = lbl_80529CF8;
    u16 count = 0;

    if (*(unsigned char*)(base + 0x14D) != 0) {
        count = 1;
    }
    if (*(unsigned char*)(base + 0x269) != 0) {
        count = (u16)(count + 1);
    }
    if (*(unsigned char*)(base + 0x385) != 0) {
        count = (u16)(count + 1);
    }
    if (*(unsigned char*)(base + 0x4A1) != 0) {
        count = (u16)(count + 1);
    }
    return count;
}
