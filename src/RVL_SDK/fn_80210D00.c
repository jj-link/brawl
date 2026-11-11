#include <types.h>
#pragma force_active on
typedef struct { u32 offset, count, unk8; } Entry;
typedef struct { u32 unk0; Entry *entries; u32 unk8, unkC; char *base; } Node;
static u32 copy(char *dst, const char *src, u32 n) {
    u32 left = n;
    while (left && *src) {
        *dst++ = *src++;
        left--;
    }
    return n - left;
}
u32 fn_80210D00(Node *node, int idx, char *buf, u32 size) {
    Entry *entries = node->entries;
    char *name;
    u32 len;
    if (!idx) return 0;
    name = node->base + (entries[idx].offset & 0xffffff);
    len = fn_80210D00(node, entries[idx].count, buf, size);
    if (len == size) return len;
    buf[len++] = '/';
    return len + copy(buf + len, name, size - len);
}