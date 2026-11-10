#pragma force_active on

extern char lbl_80490E60[0x130];
extern char lbl_8059FBE8[8];
int strcmp(const char *s1, const char *s2);

int fn_8038D850(const char *arg0) {
    char *base = lbl_80490E60;
    int result;
    int comparison;

    if (strcmp(arg0, lbl_8059FBE8) == 0) {
        return 0;
    }
    if (strcmp(arg0, base + 0x20) == 0) {
        return 1;
    }
    if (strcmp(arg0, base + 0x38) == 0) {
        return 2;
    }
    if (strcmp(arg0, base + 0x48) == 0) {
        return 7;
    }
    if (strcmp(arg0, base + 0x5C) == 0) {
        return 8;
    }
    if (strcmp(arg0, base + 0x70) == 0) {
        return 9;
    }
    if (strcmp(arg0, base + 0x84) == 0) {
        return 0xA;
    }
    if (strcmp(arg0, base + 0x94) == 0) {
        return 0xB;
    }
    if (strcmp(arg0, base + 0xA4) == 0) {
        return 0xC;
    }
    if (strcmp(arg0, base + 0xB4) == 0) {
        return 0xD;
    }
    if (strcmp(arg0, base + 0xC8) == 0) {
        return 0xE;
    }
    if (strcmp(arg0, base + 0xD8) == 0) {
        return 0xF;
    }
    if (strcmp(arg0, base + 0xEC) == 0) {
        return 0x10;
    }
    if (strcmp(arg0, base + 0xFC) == 0) {
        return 0x11;
    }
    if (strcmp(arg0, base + 0x108) == 0) {
        return 0x12;
    }
    if (strcmp(arg0, base + 0x114) == 0) {
        return 0x13;
    }
    comparison = strcmp(arg0, base + 0x124);
    result = 0x15;
    if (comparison == 0) {
        result = 0x14;
    }
    return result;
}
