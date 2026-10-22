typedef unsigned short u16;
typedef unsigned int u32;

#pragma force_active on
int fn_803D91F4(void *arg0, void **arg1) {
    char *p;

    p = *(char **)((char *)arg0 + 0x24);
    while (p != (char *)arg0) {
        if (!(*(u16 *)p & 1)) {
            *arg1 = p;
            return 1;
        }
        if (*(u32 *)(p + 0x18) + 0x10000 != 0xFFFF) {
            *arg1 = p;
            return 0;
        }
        p = *(char **)(p + 0x24);
    }
    if (!(*(u16 *)p & 1)) {
        *arg1 = p;
        return 1;
    }
    if (*(u32 *)(p + 0x18) + 0x10000 != 0xFFFF) {
        *arg1 = p;
        return 0;
    }
    *arg1 = 0;
    return 0;
}
