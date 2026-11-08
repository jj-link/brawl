#pragma force_active on
typedef unsigned int u32;
extern char *lbl_805A08E4;
extern char *lbl_805A08E8;
static u32 copy(char *dst, const char *src, u32 n) {
    u32 left = n;
    while (left && *src) {
        *dst++ = *src++;
        left--;
    }
    return n - left;
}
u32 fn_801F6548(int idx, char *buf, u32 size) {
    char *name;
    u32 len;
    if (!idx) return 0;
    name = lbl_805A08E4 + (*(u32 *)(lbl_805A08E8 + idx * 12) & 0xffffff);
    len = fn_801F6548(*(int *)((lbl_805A08E8 + 4) + idx * 12), buf, size);
    if (len == size) return len;
    buf[len++] = '/';
    return len + copy(buf + len, name, size - len);
}