#pragma force_active on
extern char lbl_80490690[];
extern char lbl_8059FA78[8];

char *fn_8037F338(void *arg0) {
    char *p = *(char **)((char *)arg0 + 0x160);
    char *base = lbl_80490690;
    char *result;
    if (p == 0) return lbl_8059FA78;
    if (*(int *)(p + 0x14) != 0) return base + 0x44;
    if (*(int *)(p + 0x0c) != 0) return base + 0x58;
    result = base + 0xa8;
    if (*(int *)(p + 0x10) != 0) result = base + 0x9c;
    return result;
}