#pragma force_active on
extern char lbl_80529CF8[];
extern int fn_803F6150(const void *, const void *, unsigned long);
extern void *memcpy(void *, const void *, unsigned long);

int fn_8023CD1C(void *arg0) {
    char *base = lbl_80529CF8;
    unsigned short count;
    unsigned int *entry;
    unsigned short i;

    entry = *(unsigned int **)(base + 0x16DC);
    if ((*(unsigned char *)(base + 0x1848) & 4) || entry == 0) {
        return 0;
    }
    count = *(unsigned short *)(base + 0x16E0);
    for (i = 0; i < count; i++, entry += 3) {
        if (fn_803F6150(entry + 1, arg0, 6) == 0 && *entry == *(unsigned int *)(base + 0x16C0)) {
            return 1;
        }
    }
    if (i < *(unsigned short *)(base + 0x16E2)) {
        *entry = *(unsigned int *)(base + 0x16C0);
        memcpy(entry + 1, arg0, 6);
        *(unsigned short *)(base + 0x16E0) = *(unsigned short *)(base + 0x16E0) + 1;
    }
    return 0;
}
