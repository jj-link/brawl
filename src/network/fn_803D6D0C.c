#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
extern char lbl_805644C0[];
static inline void mark(char *p, u32 arg0) {
    if (*(u32 *)(p + 0x1FBC) == arg0)
        *(u16 *)(p + 0x1F8C) |= 0x14;
}
void fn_803D6D0C(u32 arg0) {
    char *p;
    int i;
    p = lbl_805644C0 + 0xA0;
    for (i = 0; i < 26; i++) {
        mark(p, arg0);
        p += 0x1FC8;
    }
}